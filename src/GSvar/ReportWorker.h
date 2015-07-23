#ifndef REPORTWORKER_H
#define REPORTWORKER_H

#include <QObject>
#include <QString>
#include "VariantList.h"
#include "WorkerBase.h"

///Report generation worker.
class ReportWorker
		: public WorkerBase
{
	Q_OBJECT

public:
	/*
	  @brief Constructor.
	*/
	ReportWorker(QString sample_name, QString sample_name_external, QStringList filters, const VariantList& variants, const QVector< QPair<int, bool> >& variants_selected, QString outcome, QString file_roi, QString file_bam, bool var_details, QStringList log_files, QString file_rep);
	virtual void process();

private:
	//input variables
	QString sample_name_;
	QString sample_name_external_;
	QStringList filters_;
	const VariantList& variants_;
	QVector< QPair<int, bool> > variants_selected_;
	QString outcome_;
	QString file_roi_;
	QString file_bam_;
	bool var_details_;
	QStringList genes_;
	QStringList log_files_;

	//output variables
	QString file_rep_;

	//temporary variables
	BedFile roi_;
	int var_count_;

	int annotationIndexOrException(const QString& name, bool exact_match) const;
	void writeHTML();
	void writeXML();
};

#endif


