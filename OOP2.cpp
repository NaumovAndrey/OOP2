#include <iostream>
#include <cmath>
#include <numbers>

enum Color { Red, Blue, Green, None };

class Shape
{
    protected:
    double centerX;
    double centerY;
    Color color;

    public:
    Shape(double x, double y, Color c) : centerX(x), centerY(y), color(c) {}

    virtual double area() const = 0;

    virtual void boundingBox() const = 0;

    void printInfo() const
    {
        std::cout << "Color: " << color << std::endl;
        std::cout << "Area: " << area() << std::endl;
        boundingBox();
    }
};

class Circle : public Shape
{
    private:
    double radius;

    public:
    Circle(double x, double y, Color c, double r) : Shape(x, y, c), radius(r) {}

    double area() const override
    {
        return 3,14 * radius * radius;
    }

    void boundingBox() const override
    {
        std::cout << "Bounding box: (" << centerX - radius << ", " << centerY - radius << "), (" << centerX + radius << ", " << centerY + radius << ")" << std::endl;
    }
};

class Square : public Shape
{
    private:
    double sideLength;

    public:
    Square(double x, double y, Color c, double s) : Shape(x, y, c), sideLength(s) {}

    double area() const override
    {
        return sideLength * sideLength;
    }

    void boundingBox() const override
    {
        std::cout << "Bounding box: (" << centerX - sideLength / 2 << ", " << centerY - sideLength / 2 << "), (" << centerX + sideLength / 2 << ", " << centerY + sideLength / 2 << ")" << std::endl;
    }
};

class Triangle : public Shape
{
    private:
    double sideLength;

    public:
    Triangle(double x, double y, Color c, double s) : Shape(x, y, c), sideLength(s) {}

    double area() const override
    {
        return sideLength * sideLength * std::sqrt(3) / 4;
    }

    void boundingBox() const override
    {
        std::cout << "Bounding box: (" << centerX - sideLength / 2 << ", " << centerY - sideLength / (2 * std::sqrt(3)) << "), (" << centerX + sideLength / 2 << ", " << centerY + sideLength / (2 * std::sqrt(3)) << ")" << std::endl;
    }
};

class Rectangle : public Shape
{
    private:
    double width;
    double height;

    public:
    Rectangle(double x, double y, Color c, double w, double h) : Shape(x, y, c), width(w), height(h) {}

    double area() const override
    {
        return width * height;
    }

    void boundingBox() const override
    {
        std::cout << "Bounding box: (" << centerX - width / 2 << ", " << centerY - height / 2 << "), (" << centerX + width / 2 << ", " << centerY + height / 2 << ")" << std::endl;
    }
};

double inputNumber(const std::string& prompt)
{
    double num;
    std::cout << prompt;
    while (!(std::cin >> num))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ошибка ввода. Пожалуйста, введите числовое значение: ";
    }
    return num;
}

int main()
{
    setlocale(LC_ALL, "rus");
    std::string command;
    while (true)
    {
        std::cout << "Введите команду (circle/square/triangle/rectangle/exit): ";
        std::cin >> command;

        if (command == "exit")
        {
            break;
        }

        double x = inputNumber("Введите координату x центра: ");
        double y = inputNumber("Введите координату y центра: ");

        int c;
        std::cout << "Выберите цвет (0 - Red, 1 - Blue, 2 - Green): ";
        std::cin >> c;
        Color color = static_cast<Color>(c);

        if (command == "circle")
        {
            double radius = inputNumber("Введите радиус: ");
            Circle circle(x, y, color, radius);
            circle.printInfo();
        } else if (command == "square")
        {
            double sideLength = inputNumber("Введите длину стороны: ");
            Square square(x, y, color, sideLength);
            square.printInfo();
        } else if (command == "triangle")
        {
            double sideLength = inputNumber("Введите длину стороны: ");
            Triangle triangle(x, y, color, sideLength);
            triangle.printInfo();
        } else if (command == "rectangle")
        {
            double width = inputNumber("Введите ширину: ");
            double height = inputNumber("Введите высоту: ");
            Rectangle rectangle(x, y, color, width, height);
            rectangle.printInfo();
        } else
        {
            std::cout << "Некорректная команда. Попробуйте снова." << std::endl;
        }
    }

    return 0;
}