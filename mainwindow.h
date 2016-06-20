#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <sstream>
#include <qstring.h>
#include <algoritmos_pi.h>
#include <QFileDialog>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_num_cor_actionTriggered(int action);

    void on_esp_horiz_clicked();

    void on_quantizacao_clicked();

    void on_esp_vertic_clicked();

    void on_Tons_cinza_clicked();

    void on_num_luminosidade_actionTriggered(int action);

    void on_contraste_clicked();

    void on_num_contraste_actionTriggered(int action);

    void on_copia_clicked();

    void on_luminosidade_clicked();

    void on_salvar_clicked();

    void on_abrir_clicked();

    void on_abrir_linha_editingFinished();

    void on_pushButton_clicked();

    void on_buttom_negative_clicked();

    void on_buttom_equalization_clicked();

    QImage open_image();


private:
    Ui::MainWindow *ui;
    QImage imagem;
    Algoritmos_PI meupi;
    QString endereco;
    Mat img, img2;
    bool flag;

    String end;
};

#endif // MAINWINDOW_H
