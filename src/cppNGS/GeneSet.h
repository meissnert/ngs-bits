#ifndef GENESET_H
#define GENESET_H

#include "cppNGS_global.h"
#include <QList>
#include <QSet>
#include <QByteArray>
#include <QDataStream>

// A set of gene names (sorted, upper-case and without duplicates)
class CPPNGSSHARED_EXPORT GeneSet
	: protected QList<QByteArray>
{
	public:
		//Default contstructor
		GeneSet();

		using QList<QByteArray>::clear;
		using QList<QByteArray>::count;
		using QList<QByteArray>::operator[];
		using QList<QByteArray>::join;
		using QList<QByteArray>::isEmpty;
		using QList<QByteArray>::const_iterator;
		using QList<QByteArray>::begin;
		using QList<QByteArray>::end;
		using QList<QByteArray>::cbegin;
		using QList<QByteArray>::cend;

		///Inserts a gene
		void insert(const QByteArray& gene);

		///Inserts a gene list
		void insert(const GeneSet& genes)
		{
			foreach(const QByteArray& gene, genes)
			{
				insert(gene);
			}
		}

		///Inserts a gene list
		void insert(const QByteArrayList& genes)
		{
			foreach(const QByteArray& gene, genes)
			{
				insert(gene);
			}
		}

		///Inserts a gene set
		void insert(const QSet<QByteArray>& genes)
		{
			foreach(const QByteArray& gene, genes)
			{
				insert(gene);
			}
		}


		///Inserts a gene
		GeneSet& operator<<(const QByteArray& gene)
		{
			insert(gene);
			return *this;
		}

		///Equality check
		bool operator==(const GeneSet& rhs)
		{
			return QList<QByteArray>::operator ==(rhs);
		}

		///Inequality check
		bool operator!=(const GeneSet& rhs)
		{
			return QList<QByteArray>::operator!=(rhs);
		}

		///Checks if the gene is contained
		bool contains(const QByteArray& gene) const;
		///Checks if the gene is contained
		bool containsAll(const GeneSet& genes) const;
		///Returns the intersection of two gene sets
		GeneSet intersect(const GeneSet& genes) const;
		///Checks if any gene is contained
		bool intersectsWith(const GeneSet& genes) const;

		///Load gene list from file
		static GeneSet createFromFile(QString filename);
		///Load gene list from text array
		static GeneSet createFromText(const QByteArray& text, char seperator = '\n');
		///Stores the gene set to a file
		void store(QString filename) const;
};

#endif // GENESET_H
