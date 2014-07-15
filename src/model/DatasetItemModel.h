/*
    Copyright (C) 2012  Spatial Transcriptomics AB,
    read LICENSE for licensing terms.
    Contact : Jose Fernandez Navarro <jose.fernandez.navarro@scilifelab.se>

*/

#ifndef DATASETITEMMODEL_H
#define DATASETITEMMODEL_H

#include "data/DataProxy.h"
#include <QAbstractItemModel>

class QModelIndex;
class QStandardItemModel;
class QItemSelection;

// Wrapper model class for the dataset data in the data proxy. Provides an easy
// means of enumerating all the data sets connected to a single user.
class DatasetItemModel : public QAbstractTableModel
{
    Q_OBJECT
    Q_ENUMS(Column)

public:

    enum Column {
        Name = 0,
        Tissue = 1,
        Specie = 2,
        Barcodes = 3,
        Genes = 4,
        UBarcodes = 5,
        UGenes = 6,
        Created = 7,
        LastModified = 8,
        Comments = 9
    };

    explicit DatasetItemModel(QObject* parent = 0);
    virtual ~DatasetItemModel();

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    bool setData(const QModelIndex & index,
                 const QVariant & value, int role = Qt::EditRole) override;

    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    //we do not want the user to edit columns name
    bool setHeaderData(int, Qt::Orientation,
                       const QVariant&, int = Qt::EditRole) override;

    //loads the data of the model from DatProxy
    void loadDatasets(const DataProxy::DatasetList &datasetList);

    //returns a list of datasets for the given item selection
    DataProxy::DatasetList getDatasets(const QItemSelection &selection);

private:

    //TODO make this a pure reference
    DataProxy::DatasetList m_datasets_reference;

    Q_DISABLE_COPY(DatasetItemModel)
};

#endif // DATASETITEMMODEL_H
