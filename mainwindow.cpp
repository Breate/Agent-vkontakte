#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::MainWindow)
{
    m_ui->setupUi(this);
    connect(m_ui->pushButton,SIGNAL(clicked()),this,SLOT(ok_presed()));
}

MainWindow::~MainWindow()
{
    delete m_ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::ok_presed()
{
Communicator m;

Request r;
r.setHost("vkontakte.ru");
r.setPath("login.php");/*vkontakte.ru/*/
r.setParam("act","login");
r.setParam("email","staha.by@gmail.com");
r.setParam("pass","ctfface3");
r.setoHeader("User-Agent","Mozilla/5.0 (X11; U; Linux i686; ru; rv:1.9b5) Gecko/2008050509 Firefox/3.0b5");
r.setoHeader("Accept","text/html");
m_ui->label->setText(r.toString());
Answer *a=m.get(r);
m_ui->label_2->setText(a->redirectLocate());


}
