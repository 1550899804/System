#ifndef ZHUCE_H
#define ZHUCE_H
#include <QDialog>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QCryptographicHash>
#include <QSqlError>
#include <QSqlQuery>

namespace Ui {
class Zhuce;
}

class Zhuce : public QDialog
{
    Q_OBJECT

public:
    explicit Zhuce(QWidget *parent = nullptr);
    ~Zhuce();

private slots:
    void on_pushButton_clicked();  // 确定按钮
    void on_pushButton_2_clicked();  // 取消按钮
    void on_pushButton_3_clicked();

signals:
    void registrationSuccess();  // 新增信号

private:
    Ui::Zhuce *ui;
    bool connectDB();  // 数据库连接函数
    void registerUser(const QString &username, const QString &account, const QString &password);  // 注册用户函数

    QString username;  // 用户名
    QString account;   // 账号
    QString password;  // 密码
};

#endif // ZHUCE_H
