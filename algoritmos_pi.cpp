#include "algoritmos_pi.h"


Algoritmos_PI::Algoritmos_PI()
{
}

void Algoritmos_PI::Show_Img(bool flag){
   namedWindow("Image",WINDOW_AUTOSIZE);
   (flag)?imshow("Image",image_input):imshow("Image2",image_work);
}
Mat Algoritmos_PI::Mirror_Vertic_Img(Mat img){
    int indice;
    for(int i = 0; i < img.rows;i++){
        for(int j = 0; j <= img.cols/2;j++){
            Vec3b intensity = img.at<Vec3b>(i, j);
            if(j == image_input.cols/2){
                indice = image_input.cols -j +1;
            }else{
                indice = image_input.cols -j -1;
            }
            Vec3b intensity2 = img.at<Vec3b>(i, indice);
            image_work.at<Vec3b>(i,j) = intensity2;
            image_work.at<Vec3b>(i,indice) = intensity;
        }
    }
    return image_work;
}
Mat Algoritmos_PI::Mirror_Horizon_Img(Mat img){
    int indice;
    for(int i = 0; i <= img.rows/2;i++){
        for(int j = 0; j < img.cols;j++){
            Vec3b intensity = img.at<Vec3b>(i, j);
            if(i == img.rows/2){
                indice = img.rows -i +1;
            }else{
                indice = img.rows -i -1;
            }
            Vec3b intensity2 = img.at<Vec3b>(indice, j);
            image_work.at<Vec3b>(i,j) = intensity2;
            image_work.at<Vec3b>(indice, j) = intensity;
        }
    }
    return image_work;
}

Mat Algoritmos_PI::Conver2Gray_Img(Mat img){
   for(int i = 0; i < img.rows;i++){
       for(int j = 0; j < img.cols;j++){
           Vec3b intensity = img.at<Vec3b>(i, j);
           float value = intensity.val[0]*0.299 + intensity.val[1]*0.587 +  intensity.val[2]*0.114;
           intensity.val[0] = intensity.val[1] = intensity.val[2] = value;
           image_work.at<Vec3b>(i,j) = intensity;
       }
   }
   return image_work;
}
void Algoritmos_PI::Save_Img(Mat img){
    imwrite("resultado.jpg",img);
}

void Algoritmos_PI::Save_Img2(Mat img){
    imwrite("histogram.jpg",img);
}

Mat Algoritmos_PI::Quantization(Mat img,int value){
    int distLevel = (256/value);
    Vec3b intensity, intensity2;

    for(int i = 0; i < img.rows;i++){
        for(int j = 0; j < img.cols;j++){
            intensity = img.at<Vec3b>(i,j);
            for(int k = 0; k < 3; k++){
                intensity2.val[k] = floor(((float)intensity.val[k]/distLevel))*distLevel + (distLevel/2);
                if((float)intensity2.val[k] > 255) intensity2.val[k] = 255;
            }
            image_work.at<Vec3b>(i,j) = intensity2;
        }
    }
    return image_work;
}

Mat Algoritmos_PI::Luminance_Img(Mat img,int value){
    Vec3b intensity;
    cout<<value<<endl;
    for(int i = 0; i < img.rows;i++){
            for(int j = 0; j < img.cols;j++){
                intensity = img.at<Vec3b>(i,j);
                for(int k = 0; k < 3; k++){
                    if((int)intensity.val[k] + value < 0)intensity.val[k] = 0;
                    else{
                        if((int)intensity.val[k] + value > 255) intensity.val[k] = 255;
                        else intensity.val[k] = (int)intensity.val[k] + value;
                    }
                }
                image_work.at<Vec3b>(i,j) = intensity;
            }
        }
    return image_work;
}
Mat Algoritmos_PI::Contrast_Img(Mat img, float value){
    Vec3b intensity;
    for(int i = 0; i < img.rows;i++){
            for(int j = 0; j < img.cols;j++){
                intensity = img.at<Vec3b>(i,j);
                for(int k = 0; k < 3; k++){
                    if((float)intensity.val[k]*value < 0)intensity.val[k] = 0;
                    else{
                        if((float)intensity.val[k]*value > 255) intensity.val[k] = 255;
                        else intensity.val[k] = (int)(value * (float)intensity.val[k]);
                    }
                }
                image_work.at<Vec3b>(i,j) = intensity;
            }
        }
    return image_work;
}

Mat Algoritmos_PI::Open(String endereco){
    image_input = imread(endereco.c_str());
    image_work = Mat(image_input.rows,image_input.cols,CV_8UC3);
    return image_input;
}

Mat Algoritmos_PI::getImage(){
    return image_work;
}

void Algoritmos_PI::setImage(Mat img){
    image_work = img;
}

Mat Algoritmos_PI::Histograma(Mat img){
    int bins = 256;             // number of bins
    vector<Mat> hist(1);       // array for storing the histograms
    Mat Myimg;
    int hmax[1] = {0};      // peak value for each histogram

    for (int i = 0; i < hist.size(); i++)
        hist[i] = Mat::zeros(1, bins, CV_32SC1);

    for (int i = 0; i < img.rows; i++){
        for (int j = 0; j < img.cols; j++){
            uchar val = img.at<uchar>(i,j);
            hist[0].at<int>(val) += 1;
        }
    }


    for (int j = 0; j < bins-1; j++)
        hmax[0] = hist[0].at<int>(j) > hmax[0] ? hist[0].at<int>(j) : hmax[0];

    Myimg = Mat::ones(256,bins,CV_8UC3);

    for (int j = 0, rows = Myimg.rows; j < bins-1; j++){
        line(Myimg,
            Point(j, rows),
            Point(j, rows - (hist[0].at<int>(j) * rows/hmax[0])),
            Scalar(200,200,200),
            1, 8, 0);
    }
    return Myimg;
}

void Algoritmos_PI::set_Flag_Abrir(bool n){flag_abrir = n;}
void Algoritmos_PI::set_Flag_Copia(bool n){flag_copia = n;}
void Algoritmos_PI::set_Flag_Cinza(bool n){flag_cinza = n;}
bool Algoritmos_PI::get_Flag_Abrir(){return flag_abrir;}
bool Algoritmos_PI::get_Flag_Copia(){return flag_copia;}
bool Algoritmos_PI::get_Flag_Cinza(){return flag_cinza;}

Mat Algoritmos_PI::Negative(Mat img){
    Vec3b intensity;
    for(int i = 0; i < img.rows;i++){
            for(int j = 0; j < img.cols;j++){
                intensity = img.at<Vec3b>(i,j);
                for(int k = 0; k < 3; k++){
                    if(255 - (int)intensity.val[k] < 0)intensity.val[k] = 0;
                    else{
                        intensity.val[k] = 255 - (int)intensity.val[k];
                    }
                }
                image_work.at<Vec3b>(i,j) = intensity;
            }
        }
    return image_work;
}

Mat Algoritmos_PI::Equalization(Mat img){
    Vec3b intensity;
    float a = img.rows*img.cols, bins = 255.;
    float hist[256];

    memset(hist,0,sizeof(hist));

    cout<<"TESTE"<<endl;

    //CALCULATING THE HISTOGRAM
    for(int i = 0; i < img.rows; i++){
        for(int j = 0; j < img.cols; j++){
            intensity = img.at<uchar>(i,j);
            hist[(int)intensity.val[0]] += 1;
        }
    }

    //NORMALIZED HISTOGRAM
    for(int i = 0; i < 256; i++){
        hist[i] = hist[i]/a;
    }

    //CUMULATIVE HISTOGRAM
    for(int i = 1; i < 256; i++){
         hist[i] += hist[i-1];
    }

    for(int i = 0; i < 256; i++){
        hist[i] = floor(hist[i]*bins);
    }

    cout<<"TESTE3"<<endl;
    for(int i = 0; i < img.rows; i++){
        for(int j = 0; j < img.cols; j++){
            intensity = img.at<Vec3b>(i,j);
            intensity.val[0] = intensity.val[1] = intensity.val[2] = hist[(int)intensity.val[0]];
            image_work.at<Vec3b>(i,j) = intensity;
        }
    }
    cout<<"TESTE4"<<endl;
    return image_work;
}


Mat Algoritmos_PI:: f(Mat img){

    cout<<"jasfkuasfafgiusfd"<<endl;
    double Tam = img.rows * img.cols;
    double tonos = 255;
    double frecuencia[256];


    memset(frecuencia, 0, sizeof(frecuencia));

    for(int i = 0; i < img.rows; i++){
        for(int j = 0; j < img.cols; j++){
            Vec3b intensity = img.at<uchar>(i,j);
            frecuencia[(int)intensity.val[0]]++;
        }
    }

    for(int i = 0; i < 256; i++){
        frecuencia[i] = frecuencia[i]/Tam;

    }

    for(int i = 1; i < 256; i++){
        frecuencia[i] = frecuencia[i] + frecuencia[i - 1];

    }

    for(int i = 0; i < 256; i++){
        frecuencia[i] = floor(frecuencia[i] * tonos);

    }

    for(int i = 0; i < img.rows; i++){
        for(int j = 0; j < img.cols; j++){
            Vec3b intensity = img.at<Vec3b>(i,j);
            intensity.val[0] = intensity.val[1] = intensity.val[2] = frecuencia[(int)intensity.val[0]];
            image_work.at<Vec3b>(i,j) = intensity;
        }
    }

    return image_work;
}
