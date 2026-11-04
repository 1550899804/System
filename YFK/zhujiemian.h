#ifndef ZHUJIEMIAN_H
#define ZHUJIEMIAN_H
#include <QMainWindow>
#include <QLabel> // 添加 QLabel 头文件
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QFileDialog>
#include <QPixmap>
#include <QByteArray>
#include <QMap>
#include <QMouseEvent>
#include <QListWidgetItem>

namespace Ui {
class Zhujiemian;
}

// 自定义的右区域类（热区图片）
class RightArea : public QLabel {
    Q_OBJECT

public:
    explicit RightArea(QWidget *parent = nullptr);
protected:
    void mouseMoveEvent(QMouseEvent *event) override;
private:
    void determineRegionAndUpdateImage(const QPoint &pos);
signals:
    void imageChanged(const QString &path);
};


class Zhujiemian : public QMainWindow
{
    Q_OBJECT

public:
    explicit Zhujiemian(QWidget *parent = nullptr);
    ~Zhujiemian();
    void inittreeWidget();

    /*导航类型*/
    enum InitType
    {
        User_Search,   // 人员管理 - 查找用户
        User_Add,      // 人员管理 - 添加用户
        Warehouse,     // 仓库管理
        Logistics,     // 物流管理
        Messaging     // 信息收发
    };
    void cutPage(InitType type);
    void on_userSearch();

private slots:
    void updateTime(); // 新增槽函数声明
    void on_pushButton_clicked();  // 确认修改
    void on_pushButton_2_clicked(); // 返回登录
    void on_pushButton_3_clicked();  // 确认删除
    void on_pushButton_4_clicked();  // 返回主界面
    void on_pushButton_5_clicked();   // 修改员工信息
    void on_pushButton_6_clicked();   // 删除员工信息
    void on_pushButton_7_clicked();   // 新增员工信息
    void on_pushButton_8_clicked();   // 刷新表格
    void on_pushButton_9_clicked(); // 新增按钮点击事件
    void on_tableWidget_itemSelectionChanged(); // 选中行变化
    void on_tableWidget_2_itemSelectionChanged(); // 新增槽函数：订单表选中行变化
    // 添加数据库连接函数
    bool connectDB();
    // 新增槽函数：更新左边图片
    void updateLeftImage(const QString &path);
    void on_listWidget_2_itemEntered(QListWidgetItem *item); // 新增槽函数：鼠标悬停在列表项上
    void setFiveQrcImages();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    Ui::Zhujiemian *ui;
    QLabel *timeLabel; // 新增 QLabel 成员变量
    QString currentUser = "YFK";      // 当前登录用户
    QMap<int, QByteArray> imageCache; // 行号 -> 图片二进制数据
    void loadEmployeeData();          // 加载员工数据
    void showImageForRow(int row);    // 显示选中行图片
    void loadEvents();                // 加载事件数据
    void loadOrdersData();            // 加载订单数据
    void loadGoodsData();             // 加载货物数据
    void loadEmployeeImages();        // 加载员工图片
    QLabel *label_11;                 // 确保UI中存在此控件
    bool dragging = false;
    QPoint dragPosition;
    RightArea *rightArea; // 右边热区区域
    QLabel *leftLabel;    // 左边显示动态图片的标签
    QListWidgetItem *currentHoveredItem; // 当前悬停的列表项
    // ... 其他现有成员变量 ...
};

#endif // ZHUJIEMIAN_H

