#include <iostream>
#include <string>
using namespace std;

class ParcelAnalyzer {
public:
   
    string classifyWeight(int grams) {
        if (grams < 500) return "Light";
        else if (grams <= 2000) return "Medium";
        else return "Heavy";
    }

 
    string classifyWeight(float kilograms) {
        if (kilograms < 0.5f) return "Light";
        else if (kilograms <= 2.0f) return "Medium";
        else return "Heavy";
    }

   
    string classifyWeight(double pounds) {
        if (pounds < 1.1) return "Light";
        else if (pounds <= 4.4) return "Medium";
        else return "Heavy";
    }
};


void printClassification(const string& label) {
    cout << "Classification: " << label << endl;
}

int main() {
    ParcelAnalyzer analyzer;

    
    printClassification(analyzer.classifyWeight(450));    
    printClassification(analyzer.classifyWeight(1500));   
    printClassification(analyzer.classifyWeight(2500));  

    printClassification(analyzer.classifyWeight(0.3f));   
    printClassification(analyzer.classifyWeight(1.5f));  
    printClassification(analyzer.classifyWeight(3.0f));   

    printClassification(analyzer.classifyWeight(0.9));    
    printClassification(analyzer.classifyWeight(2.5));   
    printClassification(analyzer.classifyWeight(5.0));   

    return 0;
}
