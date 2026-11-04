#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDialog>  // 改为继承QDialog
#include <QSqlDatabase>
#include <QMessageBox>
#include <QCryptographicHash>
#include <QStackedWidget>
#include <QToolButton>
#include "zhujiemian.h"    // 主界面头文件
#include "zhuce.h"         // 注册界面头文件

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();      // 登录按钮
    void on_pushButton_2_clicked();    // 退出按钮
    void on_pushButton_3_clicked();    // 注册按钮
    void on_pushButton_5_clicked();
protected:
    // 声明鼠标事件处理函数
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    Ui::MainWindow *ui;
    Zhujiemian *mainInterface;         // 主界面指针
    bool connectDB();                  // 数据库连接函数
    bool validateAccount(const QString &account);  // 验证账号是否存在
    bool validatePassword(const QString &account, const QString &password); // 验证密码
    QString getFullName(const QString &username);  // 获取用户姓名
    bool dragging;
    QPoint dragPosition;
};

#endif // MAINWINDOW_H
