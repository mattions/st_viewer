/*
    Copyright (C) 2012  Spatial Transcriptomics AB,
    read LICENSE for licensing terms.
    Contact : Jose Fernandez Navarro <jose.fernandez.navarro@scilifelab.se>

*/

#ifndef DATASETSTABLEVIEW_H
#define DATASETSTABLEVIEW_H

#include <QTableView>

class DatasetItemModel;

class DatasetsTableView : public QTableView
{
    Q_OBJECT

public:

    explicit DatasetsTableView(QWidget *parent = 0);
    virtual ~DatasetsTableView();

private:

    DatasetItemModel *m_datasetModel;

    Q_DISABLE_COPY(DatasetsTableView)
};

#endif // DATASETSTABLEVIEW_H //