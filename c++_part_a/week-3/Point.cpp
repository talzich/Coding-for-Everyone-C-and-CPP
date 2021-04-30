//
// AUTHOR: Tal Zichlinsky

class point{
    
    double x, y;
    const int tester;

    public:
        // Constructor of preferred type
        // The reason this constructor is preferred is that the members are considered initialized and not assignment so we can assign a value to a const member
        point(double x = 0.0, double y = 0.0):x(x), y(y), tester(10){}

        // point(double x, double y, int tester){
        //     this->x = x; 
        //     this->y = y; 
        //     // this->tester = tester; This line will not compile because this style of assignment is considered mutating
        // }
        
        // Getters & Setters
        double get_x() const { return x; }
        double get_y() const { return y; }

        void set_x(double x){ this->x = x; } 
        void set_y(double y){ this->y = y; }

};