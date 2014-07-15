#include "CreateSelectionDialog.h"

#include "ui_createSelectionDialog.h"

CreateSelectionDialog::CreateSelectionDialog(QWidget* parent, Qt::WindowFlags f)
    : QDialog(parent, f),
      ui(new Ui::createSelectionDialog)
{
    ui->setupUi(this);

    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
}

CreateSelectionDialog::~CreateSelectionDialog()
{
    delete ui;
    ui = nullptr;
}

const QString CreateSelectionDialog::getName() const
{
    return ui->name->text();
}

const QString CreateSelectionDialog::getComment() const
{
    return ui->comment->toPlainText();
}

void CreateSelectionDialog::setName(const QString name)
{
    return ui->name->setText(name);
}

void CreateSelectionDialog::setComment(const QString comment)
{
    return ui->comment->setText(comment);
}
