
QT       += gui widgets network sql xml xmlpatterns printsupport
QTPLUGIN += QSQLMYSQL

TARGET = GSvar
TEMPLATE = app
RC_FILE	 = icon.rc

SOURCES += main.cpp\
    MainWindow.cpp \
    FilterDockWidget.cpp \
    ExternalToolDialog.cpp \
    ReportDialog.cpp \
    ReportWorker.cpp \
    SampleInformationDialog.cpp \
    TrioDialog.cpp \
    HttpHandler.cpp \
    ValidationDialog.cpp \
    ClassificationDialog.cpp \
    DBAnnotationWorker.cpp \
    FilterColumnWidget.cpp \
    ApprovedGenesDialog.cpp \
    GeneInfoDialog.cpp \
    PhenoToGenesDialog.cpp \
    PhenotypeSelector.cpp \
    GenesToRegionsDialog.cpp \
    VariantDetailsDockWidget.cpp \
    SubpanelDesignDialog.cpp \
    SubpanelArchiveDialog.cpp \
    IgvDialog.cpp \
    GapDialog.cpp \
    GapValidationLabel.cpp \
    CnvWidget.cpp \
    GeneSelectorDialog.cpp \
    MultiSampleDialog.cpp \
    NGSDReannotationDialog.cpp \
    DiseaseInfoDialog.cpp \
    CandidateGeneDialog.cpp \
    PhenotypeSelectionWidget.cpp \
    LovdUploadDialog.cpp \
	RohWidget.cpp \
    ReportHelper.cpp \

HEADERS  += MainWindow.h \
    FilterDockWidget.h \
    ExternalToolDialog.h \
    ReportDialog.h \
    ReportWorker.h \
    SampleInformationDialog.h \
    TrioDialog.h \
    HttpHandler.h \
    ValidationDialog.h \
    ClassificationDialog.h \
    DBAnnotationWorker.h \
    FilterColumnWidget.h \
    ApprovedGenesDialog.h \
    GeneInfoDialog.h \
    PhenoToGenesDialog.h \
    PhenotypeSelector.h \
    GenesToRegionsDialog.h \
    VariantDetailsDockWidget.h \
    SubpanelDesignDialog.h \
    SubpanelArchiveDialog.h \
    IgvDialog.h \
    GapDialog.h \
    GapValidationLabel.h \
    CnvWidget.h \
    GeneSelectorDialog.h \
    MultiSampleDialog.h \
    NGSDReannotationDialog.h \
    DiseaseInfoDialog.h \
    CandidateGeneDialog.h \
    PhenotypeSelectionWidget.h \
    LovdUploadDialog.h \
	RohWidget.h \
    ReportHelper.h \

FORMS    += MainWindow.ui \
    FilterDockWidget.ui \
    ExternalToolDialog.ui \
    ReportDialog.ui \
    SampleInformationDialog.ui \
    TrioDialog.ui \
    ClassificationDialog.ui \
    ValidationDialog.ui \
    FilterColumnWidget.ui \
    ApprovedGenesDialog.ui \
    GeneInfoDialog.ui \
    PhenoToGenesDialog.ui \
    PhenotypeSelector.ui \
    GenesToRegionsDialog.ui \
    VariantDetailsDockWidget.ui \
    SubpanelDesignDialog.ui \
    SubpanelArchiveDialog.ui \
    IgvDialog.ui \
    GapDialog.ui \
    GapValidationLabel.ui \
    CnvWidget.ui \
    GeneSelectorDialog.ui \
    MultiSampleDialog.ui \
    NGSDReannotationDialog.ui \
    DiseaseInfoDialog.ui \
    CandidateGeneDialog.ui \
    PhenotypeSelectionWidget.ui \
    LovdUploadDialog.ui \
	RohWidget.ui \
    

include("../app_gui.pri")


#include NGSD library
INCLUDEPATH += $$PWD/../cppNGSD
LIBS += -L$$PWD/../bin -lcppNGSD

RESOURCES += \
    GSvar.qrc
