class Solution {
public:
    double pow(double x, int n) {
        if(n < 0)
            return 1.0 / power(x, -n);
        else
            return power(x, n);
    }
private:
    bool eq(double a, double b) {
        return abs(a - b) < 1e-10;
    }
    
    double power(double x, int n){
        if(eq(x,0.0) && n < 0)
            throw new exception();
        else if(eq(x,1.0))
            return 1.0;
        else if(n == 0)
            return 1.0;
        else if(n == 1)
            return x;
        double a = pow(x, n / 2);
        if(n % 2 == 0)
            return a * a;
        else
            return a * a * x;
    }
};

