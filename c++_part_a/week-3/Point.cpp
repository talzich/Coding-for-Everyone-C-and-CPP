//
// AUTHOR: Tal Zichlinsky

class point{
    
    double x, y;
    
    public:
        // Constructor
        point(double x = 0.0, double y = 0.0):x(x), y(y){}

        // Getters & Setters
        double get_x() const { return x; }
        double get_y() const { return y; }

        void set_x(double x){ this->x = x; } 
        void set_y(double y){ this->y = y; }

};