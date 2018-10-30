#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <iostream>
#include <fstream>

struct Point{
    float x;
    float y;
    char Name;
};

float distance(Point A, Point B);
float perimeter(Point Array[4]);
float area(Point Array[4]);
QString writeIntoTextFile(Point Array[4]);

int main()
{
    Point quadOne[4];
    Point quadTwo[4];

    quadOne[0].Name='A';
    quadOne[0].x=-0.0;
    quadOne[0].y=-0.0;

    quadOne[1].Name='B';
    quadOne[1].x=4.0;
    quadOne[1].y=-0.0;

    quadOne[2].Name='C';
    quadOne[2].x=4.0;
    quadOne[2].y=4.0;

    quadOne[3].Name='D';
    quadOne[3].x=-0.0;
    quadOne[3].y=4.0;

    quadTwo[0].Name='E';
    quadTwo[0].x=-10;
    quadTwo[0].y=-10;

    quadTwo[1].Name='F';
    quadTwo[1].x=10;
    quadTwo[1].y=-10;

    quadTwo[2].Name='G';
    quadTwo[2].x=10;
    quadTwo[2].y=10;

    quadTwo[3].Name='H';
    quadTwo[3].x=-10;
    quadTwo[3].y=10;

    QFile txt("results.txt");
    if (txt.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream writeStream(&txt);
        writeStream << writeIntoTextFile(quadOne);
        writeStream << writeIntoTextFile(quadTwo);
        txt.close();
        std:: cout << "Done. Check the \"results.txt\" file in project's bulid directory.";
    }
    return 0;
}

float distance(Point A, Point B) {
    int distance = sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
    return distance;
}

float perimeter(Point Array[4]) {
    float AB = distance(Array[0], Array[1]);
    float BC = distance(Array[1], Array[2]);
    float CD = distance(Array[2], Array[3]);
    float DA = distance(Array[0], Array[3]);

    float perimeter = AB + BC + CD + DA;
    return perimeter;
}

float area(Point Array[4]) {
    float AB = distance(Array[0], Array[1]);
    float BC = distance(Array[1], Array[2]);
    float CD = distance(Array[2], Array[3]);
    float DA = distance(Array[0], Array[3]);
    float d = sqrt(2) * AB;

    float p1 = (AB + BC + d) / 2;
    float p2 = (CD + DA + d) / 2;

    float area1 = sqrt(p1 * (p1 - AB) * (p1 - BC) * (p1 - d));
    float area2 = sqrt(p2 * (p2 - CD) * (p2 - DA) * (p2 - d));
    float area = area1 + area2;
    return area;
}

QString writeIntoTextFile(Point Array[4]) {
    QString text, temp;
    Point current;

    text = "Quadrilateral with points: ";
    for (int i=0; i < 4; i++) {
        current = Array[i];
        temp = "%1[%2;%3] ";
        temp = temp.arg(current.Name).arg(current.x).arg(current.y);
        text.append(temp);
    }
    temp = "\r\nHas perimeter %1 and area %2\r\n";
    temp = temp.arg(perimeter(Array)).arg(area(Array));
    text.append(temp);

    return text;
}
