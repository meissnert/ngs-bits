#ifndef MULTISAMPLEDIALOG_H
#define MULTISAMPLEDIALOG_H

#include <QDialog>
#include "ui_MultiSampleDialog.h"
#include "NGSD.h"

//Dialog used to start a multi-sample analysis.
class MultiSampleDialog
	: public QDialog
{
	Q_OBJECT

public:
	MultiSampleDialog(QWidget* parent = 0);

	//Returns the sample name list (the first sample defines the target region to use for the multi-sample analysis, if they are not the same)
	QStringList samples();
	//Rreturns the sample status list (affected/control)
	QStringList status();

protected slots:
	void on_add_control_clicked(bool);
	void on_add_affected_clicked(bool);
	void updateStartButton();
	void startAnalysis();

private:
	Ui::MultiSampleDialog ui_;
	NGSD db_;
	struct SampleInfo
	{
		QString name;
		QString system;
		bool affected;
		QString quality;
	};
	QList<SampleInfo> samples_;

	void addSample(bool affected);
	QString formatAffected(bool affected);
	void updateSampleTable();
};

#endif // MULTISAMPLEDIALOG_H
