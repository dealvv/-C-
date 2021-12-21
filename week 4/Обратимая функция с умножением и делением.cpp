#include <iostream>
#include <vector>
using namespace std;

struct Image {
    double quality;
    double freshness;
    double rating;
};

struct Params {
    double a;
    double b;
    double c;
};

class FunctionPart {
public:
    FunctionPart(char& new_s, double& new_value) {
        s = new_s;
        value = new_value;
    }
    void Apply(double& new_value) const {
        if (s == '+') new_value += value;
        else if (s == '-') new_value -= value;
        else if (s == '*') new_value *= value;
        else new_value /= value;
    }
    void Invert() {
        if (s == '+') s = '-';
        else if (s == '-') s = '+';
        else if (s == '*') s = '/';
        else s = '*';
    }
private:
    char s;
    double value;
};

class Function {
public:
    void AddPart(char s, double value) {
        parts.push_back({ s, value });
    }
    double Apply(double value) const {
        for (auto& part : parts) {
            part.Apply(value);
        }
        return value;
    };
    void Invert() {
        for (auto& part : parts) {
            part.Invert();
        }
        reverse(parts.begin(), parts.end());
    };
private:
    vector<FunctionPart> parts;
};

Function MakeWeightFunction(const Params& params,
    const Image& image) {
    Function function;
    function.AddPart('*', params.a);
    function.AddPart('-', image.freshness * params.b);
    function.AddPart('+', image.rating * params.c);
    return function;
}

double ComputeImageWeight(const Params& params, const Image& image) {
    Function function = MakeWeightFunction(params, image);
    return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params,
    const Image& image,
    double weight) {
    Function function = MakeWeightFunction(params, image);
    function.Invert();
    return function.Apply(weight);
}

int main() {
    Image image = { 10, 2, 6 };
    Params params = { 4, 2, 6 };
    cout << ComputeImageWeight(params, image) << endl;
    cout << ComputeQualityByWeight(params, image, 52) << endl;
    return 0;
}
