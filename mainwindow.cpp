#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->image1->setFixedHeight(460);
    ui->image1->setFixedWidth(400);
    ui->image2->setFixedHeight(460);
    ui->image2->setFixedWidth(400);
    ui->label_histograma->setFixedHeight(256);
    ui->label_histograma->setFixedWidth(256);

    meupi.set_Flag_Abrir(false);
    meupi.set_Flag_Cinza(false);
    meupi.set_Flag_Copia(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_num_cor_actionTriggered(int action)
{
    cout<<"Num cor:"<<ui->num_cor->value()<<endl;
    int value = 0;
    value = ui->num_cor->value();
    stringstream temp;
    temp<<value;
    string out;
    out = temp.str();
    QString nome = QString::fromUtf8(out.c_str());
    ui->label->setText(nome);
}

void MainWindow::on_esp_horiz_clicked()
{
    if(meupi.get_Flag_Abrir() && meupi.get_Flag_Copia()){
        cout<<"Esp_Horiz."<<endl;
        img = meupi.getImage();
        meupi.Mirror_Horizon_Img(img);
        meupi.Save_Img(img);
        imagem.load("/home/mathias/Área de Trabalho/build-GI_PI_Trabalho-Desktop_Qt_5_3_GCC_64bit-Debug/resultado.jpg");
        ui->image2->setScaledContents(true);
        ui->image2->setAlignment(Qt::AlignCenter);
        ui->image2->setPixmap(QPixmap::fromImage(imagem));
    }
}

void MainWindow::on_quantizacao_clicked()
{
    if(meupi.get_Flag_Abrir() && meupi.get_Flag_Copia()){
        cout<<"quant"<<endl;
        img = meupi.getImage();
        meupi.Quantization(img,ui->num_cor->value());
        meupi.Save_Img(img);
        imagem.load("/home/mathias/Área de Trabalho/build-GI_PI_Trabalho-Desktop_Qt_5_3_GCC_64bit-Debug/resultado.jpg");
        ui->image2->setScaledContents(true);
        ui->image2->setAlignment(Qt::AlignBottom);
        ui->image2->setPixmap(QPixmap::fromImage(imagem));
    }
}

void MainWindow::on_esp_vertic_clicked()
{
    if(meupi.get_Flag_Abrir() && meupi.get_Flag_Copia()){
        cout<<"Esp_Vertic."<<endl;
        img = meupi.getImage();
        meupi.Mirror_Vertic_Img(img);
        meupi.Save_Img(img);
        imagem.load("/home/mathias/Área de Trabalho/build-GI_PI_Trabalho-Desktop_Qt_5_3_GCC_64bit-Debug/resultado.jpg");
        ui->image2->setScaledContents(true);
        ui->image2->setAlignment(Qt::AlignCenter);
        ui->image2->setPixmap(QPixmap::fromImage(imagem));
    }
}

void MainWindow::on_Tons_cinza_clicked()
{
    if(meupi.get_Flag_Abrir() && meupi.get_Flag_Copia()){
        cout<<"Cinza"<<endl;
        img = meupi.getImage();
        meupi.Conver2Gray_Img(img);
        meupi.Save_Img(img);

        imagem.load("/home/mathias/Área de Trabalho/build-GI_PI_Trabalho-Desktop_Qt_5_3_GCC_64bit-Debug/resultado.jpg");
        ui->image2->setScaledContents(true);
        ui->image2->setAlignment(Qt::AlignCenter);
        ui->image2->setPixmap(QPixmap::fromImage(imagem));
        meupi.set_Flag_Cinza(true);
    }
}

void MainWindow::on_num_luminosidade_actionTriggered(int action)
{
    cout<<"Num luminosidade:"<<ui->num_luminosidade->value()<<endl;
    int value = 0;
    value = ui->num_luminosidade->value();
    stringstream temp;
    temp<<value;
    string out;
    out = temp.str();
    QString nome = QString::fromUtf8(out.c_str());
    ui->label_luminosidade->setText(nome);
}

void MainWindow::on_contraste_clicked()
{
    if(meupi.get_Flag_Abrir() && meupi.get_Flag_Copia()){
        cout<<"contraste"<<endl;
        img = meupi.getImage();
        img = meupi.Contrast_Img(img,ui->num_contraste->value()/10.0);
        meupi.Save_Img(img);

        imagem.load("/home/mathias/Área de Trabalho/build-GI_PI_Trabalho-Desktop_Qt_5_3_GCC_64bit-Debug/resultado.jpg");
        ui->image2->setScaledContents(true);
        ui->image2->setAlignment(Qt::AlignCenter);
        ui->image2->setPixmap(QPixmap::fromImage(imagem));
    }
}

void MainWindow::on_num_contraste_actionTriggered(int action)
{
    cout<<"Num contraste:"<<ui->num_contraste->value()<<endl;
    float value = 0;
    value = ui->num_contraste->value();
    stringstream temp;
    temp<<value;
    string out;
    out = temp.str();
    QString nome = QString::fromUtf8(out.c_str());
    ui->label_contraste->setText(nome);
}

void MainWindow::on_copia_clicked()
{
    if(meupi.get_Flag_Abrir()){
        img2 = meupi.Open(ui->abrir_linha->text().toStdString().c_str());
        cout<<"Copia"<<endl;
        imagem.load(endereco);
        ui->image2->setScaledContents(true);
        ui->image2->setAlignment(Qt::AlignCenter);
        ui->image2->setPixmap(QPixmap::fromImage(imagem));


        meupi.Save_Img(img2);
        meupi.setImage(img2);
        cout<<"setei imagem2"<<endl;
        meupi.set_Flag_Copia(true);
        meupi.set_Flag_Cinza(false);
    }
}

void MainWindow::on_luminosidade_clicked()
{
    if(meupi.get_Flag_Abrir() && meupi.get_Flag_Copia()){
        cout<<"luminosidade"<<endl;
        img = meupi.getImage();
        img = meupi.Luminance_Img(img,ui->num_luminosidade->value());
        meupi.Save_Img(img);


        imagem.load("/home/mathias/Área de Trabalho/build-GI_PI_Trabalho-Desktop_Qt_5_3_GCC_64bit-Debug/resultado.jpg");
        ui->image2->setScaledContents(true);
        ui->image2->setAlignment(Qt::AlignCenter);
        ui->image2->setPixmap(QPixmap::fromImage(imagem));
    }

}

void MainWindow::on_salvar_clicked()
{
    if(meupi.get_Flag_Abrir() && meupi.get_Flag_Copia()){
        cout<<"SALVAR"<<endl;
        img = meupi.getImage();
        meupi.Save_Img(img);
    }
}

void MainWindow::on_abrir_clicked()
{
    cout<<"ABRIR"<<endl;
    QString end = "/home/mathias/Área de Trabalho";
    QString rest = "Image File (*.jpg)";
    endereco = QFileDialog::getOpenFileName(this,"Open File",end,rest);
    ui->abrir_linha->setText(endereco);
    imagem.load(endereco);
    ui->image1->setScaledContents(true);
    ui->image1->setAlignment(Qt::AlignCenter);
    ui->image1->setPixmap(QPixmap::fromImage(imagem));
    img = meupi.Open(ui->abrir_linha->text().toStdString().c_str());
    meupi.set_Flag_Abrir(true);
    meupi.setImage(img);
}

void MainWindow::on_abrir_linha_editingFinished()
{

    cout<<"barra de endereco"<<endl;
//    endereco = ui->abrir_linha->text().toStdString();

    imagem.load(endereco);
    ui->image1->setScaledContents(true);
    ui->image1->setAlignment(Qt::AlignCenter);
    ui->image1->setPixmap(QPixmap::fromImage(imagem));
    img = meupi.Open(ui->abrir_linha->text().toStdString().c_str());

    meupi.setImage(img);
}

void MainWindow::on_pushButton_clicked()
{
    Mat result;
    if(meupi.get_Flag_Abrir() && meupi.get_Flag_Copia()){
        img = meupi.getImage();
        result = meupi.Histograma(img);
        meupi.Save_Img2(result);
        imagem.load("/home/mathias/Área de Trabalho/build-GI_PI_Trabalho-Desktop_Qt_5_3_GCC_64bit-Debug/histogram.jpg");
        ui->label_histograma->setScaledContents(true);
        ui->label_histograma->setAlignment(Qt::AlignCenter);
        ui->label_histograma->setPixmap(QPixmap::fromImage(imagem));
    }
}

void MainWindow::on_buttom_negative_clicked()
{
    if(meupi.get_Flag_Abrir() && meupi.get_Flag_Copia()){
        cout<<"negativo"<<endl;
        img = meupi.getImage();
        img = meupi.Negative(img);
        meupi.Save_Img(img);
        imagem.load("/home/mathias/Área de Trabalho/build-GI_PI_Trabalho-Desktop_Qt_5_3_GCC_64bit-Debug/resultado.jpg");
        ui->image2->setScaledContents(true);
        ui->image2->setAlignment(Qt::AlignCenter);
        ui->image2->setPixmap(QPixmap::fromImage(imagem));
    }
}

void MainWindow::on_buttom_equalization_clicked()
{
    if(meupi.get_Flag_Abrir() && meupi.get_Flag_Copia()){
        cout<<"equalization"<<endl;
        img = meupi.getImage();
//        img = meupi.f(img);
        img = meupi.Equalization(img);
        meupi.Save_Img(img);
        imagem.load("/home/mathias/Área de Trabalho/build-GI_PI_Trabalho-Desktop_Qt_5_3_GCC_64bit-Debug/resultado.jpg");
        ui->image2->setScaledContents(true);
        ui->image2->setAlignment(Qt::AlignCenter);
        ui->image2->setPixmap(QPixmap::fromImage(imagem));
    }
}
