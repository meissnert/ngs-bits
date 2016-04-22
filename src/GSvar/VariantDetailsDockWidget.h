#ifndef VARIANTDETAILSDOCKWIDGET_H
#define VARIANTDETAILSDOCKWIDGET_H

#include <QDockWidget>
#include <QLabel>
#include "VariantList.h"

namespace Ui {
class VariantDetailsDockWidget;
}

//Variant details widget
class VariantDetailsDockWidget
	: public QDockWidget
{
	Q_OBJECT

public:
	explicit VariantDetailsDockWidget(QWidget* parent = 0);
	~VariantDetailsDockWidget();

	//Updates the widget to a new variant.
	void updateVariant(const VariantList& vl, int index);
	//Clears the widget (no variant selected).
	void clear();

private slots:
	void nextTanscript();
	void previousTanscript();

private:
	//Database annotation datastructure
	struct DBEntry
	{
		QString id;
		QString details;
	};
	enum Color
	{
		NONE,
		RED,
		ORANGE,
		GREEN
	};

	//Returns the annotation.
	void setAnnotation(QLabel* label, const VariantList& vl, int index, QString name);
	//Convert color to string.
	static QString colorToString(Color color);
	//Format clickable link for a label.
	static QString formatLink(QString text, QString url, Color bgcolor = NONE);
	//Format colored text for a label.
	static QString formatText(QString text, Color bgcolor);
	//Parse database entries (OMIM, ClinVar, HGMD, ...) to a map (ID=>details).
	static QList<DBEntry> parseDB(QString anno);
	//Returns 'nobr' paragraph start for tooltips
	static QString nobr();

	//Init transcript details
	void initTranscriptDetails(const VariantList& vl, int index);
	//Set transcript details
	void setTranscript(int index);
	//current transcript
	int trans_curr;
	//Transcript data
	QList<QStringList> trans_data;

	Ui::VariantDetailsDockWidget *ui;
};

#endif // VARIANTDETAILSDOCKWIDGET_H
