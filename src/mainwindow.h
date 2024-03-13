#pragma once

#include <QWidget>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QTableView>
#include <QMenu>
#include <QMenuBar>
#include <QMainWindow>
// #include <QtSql>
#include <QMessageBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QLineEdit>
#include <QLabel>
#include <QComboBox>
#include <QSystemTrayIcon>

// #include "directorymodel.h"
// #include "jobsmodel.h"
// #include "job.h"
#include "inotify_service.h"

class MainWindow : public QMainWindow, public INotifyService {
    Q_OBJECT
    public:
        // INotifyService
        virtual void showSystemMessage(QString, QString) override;

    private:
        // QSqlDatabase *m_pDB;

        QTabWidget *m_pTabWidget;
        QVBoxLayout *m_pMainLayout;

        // menu and actions
        QMenu *m_pMenuFile;
        QAction *m_pActionCloneProject;
        QAction *m_pActionAddExistingProject;
        QMenu *m_pMenuHelp;
        QAction *m_pActionAbout;


        QWidget *m_pDirectoryWidget;
        QTableView *m_pTableView_Directories;
        // DirectoryModel *m_pDirectoryModel;

        QWidget *m_pFilesWidget;
        QTableView *m_pTableView_Files;
        // QSqlQueryModel *m_pFilesModel;

        // project directory
        QComboBox *m_pComboBoxProjectSelect;
        QPushButton *m_pButtonCloneProject;
        QPushButton *m_pButtonAddExisting;

        // filters
        QLineEdit *m_pLineEditNameLike;
        QLineEdit *m_pLineEditPathLike;
        QComboBox *m_pComboBox;
        QComboBox *m_pComboBoxSize;
        QLineEdit *m_pLineEditSize;
        QLineEdit *m_pLineEditComment;
        QLineEdit *m_pLineEditExt;

        QWidget *m_pJobsWidget;
        QTableView *m_pTableView_Jobs;
        // JobsModel *m_pJobsModel;

        QString m_sWorkDirectory;
        QString m_sVersionApp;

        QSystemTrayIcon* m_pTrayIcon;
        QMenu* m_pTrayIconMenu;
        QIcon m_appIcon;

        void initTrayIcon();
        // void initConnection();
        void initActions();
        void initDirectoryTabs();
        void initFilesTabs();
        void initJobsTabs();
        void terminateJob(QString sPath);

    public:

        MainWindow(QString sWorkDirectory);

    signals:

    public slots:
        void iconActivated(QSystemTrayIcon::ActivationReason);

    private slots:
        void actionAbout();
        void btnCloneProject();
        void btnAddExisting();

        void btnInsertDirectory();
        void btnScanDirectory();
        void btnFilesSearch();
};
