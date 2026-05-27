#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
class WrongLabelsFormatException {
public:

    char tekst[100];
    WrongLabelsFormatException() {

        strcpy(tekst,"Labels must have the same length");

    }
    void pecati() {
        cout<<tekst<<endl;
    }
};
class Evaluator {
protected:
    char vistinski[100];
    char predvideni[100];
public:
    Evaluator() {
        strcpy(this->vistinski,"");
        strcpy(this->predvideni,"");

    }
    Evaluator( char vistinski[100],char predvideni[100]) {
        if (strlen(vistinski)!=strlen(predvideni)) {
            throw WrongLabelsFormatException();
        }
        strcpy(this->vistinski,vistinski);
        strcpy(this->predvideni,predvideni);


    }
    Evaluator( const Evaluator &e) {
        strcpy(this->vistinski,e.vistinski);
        strcpy(this->predvideni,e.predvideni);
    }

    virtual double evaluate () const =0;
   virtual void print()=0;

    bool operator>=(const Evaluator &e) {
        if (evaluate ()>=e.evaluate ()) {
            return true;
        }
        return false;
    }
    double getEvaluator() {
        return evaluate ();
    }
    char * getPredvideni() {
        return  predvideni;
    }
    virtual ~Evaluator(){}
};
class AccuracyEvaluator: public Evaluator {
protected:
public:
    AccuracyEvaluator() {

    }
    AccuracyEvaluator( char vistinski[100],char predvideni[100]):Evaluator(vistinski,predvideni) {

    }
    AccuracyEvaluator( const AccuracyEvaluator &a):Evaluator(a) {

    }
    double evaluate ()const {
        double brojac=0;
        for (int i=0;i<strlen(vistinski);i++) {
            if (vistinski[i]==predvideni[i]) {
                brojac++;
            }
        }
        return brojac/(double)strlen(vistinski);
    }

    void print() {
        cout<<"Number of data points: "<<strlen(vistinski)<<" Prediction Accuracy: "<<evaluate ()<<endl;
    }
    virtual ~AccuracyEvaluator(){}
};
class SensitivityEvaluator: public Evaluator {
protected:
public:
    SensitivityEvaluator() {

    }
    SensitivityEvaluator( char vistinski[100],char predvideni[100]):Evaluator(vistinski,predvideni) {

    }
    SensitivityEvaluator( const SensitivityEvaluator &s):Evaluator(s) {

    }
    double evaluate ()const  {
        double brojac1=0;
        double brojac2=0;
        for (int i=0;i<strlen(vistinski);i++) {
            if (vistinski[i]==predvideni[i] && vistinski[i]=='+') {
                brojac1++;
            }
            if ( vistinski[i]=='+') {
                brojac2++;
            }
        }
        return brojac1/brojac2;
    }
    void print() {
        cout<<"Number of data points: "<<strlen(vistinski)<<" Prediction Sensitivity: "<<evaluate ()<<endl;
    }
    virtual ~SensitivityEvaluator(){}
};
Evaluator * highestScore (Evaluator ** evaluators, int n) {
    int index=0;
    for (int i=0;i<n;i++) {
        if (evaluators[i]->getEvaluator()>=evaluators[index]->getEvaluator()) {
            index=i;
        }

    }
    return evaluators[index];
}
int main() {
    ifstream input("inputEvaluator.txt");

    if (!input) {
        cout << "Cannot open file." << endl;
        return 1;
    }

    ofstream output("outputEvaluator.txt");

    if (!output) {
        cout << "Cannot open output file." << endl;
        return 1;
    }

    int n;
    input >> n;
    input.ignore();

    Evaluator** evaluators = new Evaluator*[n];

    for (int i = 0; i < n; i++) {
        char vistinski[100];
        char predvideni[100];
        char type[20];
    input.getline(vistinski, 100);
    input.getline(predvideni, 100);
    input.getline(type, 20);


            try {
            if (strcmp(type, "Accuracy") == 0) {
                evaluators[i] = new AccuracyEvaluator(vistinski, predvideni);
            } else if (strcmp(type, "Sensitivity") == 0) {
                evaluators[i] = new SensitivityEvaluator(vistinski, predvideni);
            }
        } catch (WrongLabelsFormatException &e) {
            e.pecati();
            output << e.tekst << endl;
            delete[] evaluators;
            return 1;
        }
    }

    for (int i = 0; i < n; i++) {
        evaluators[i]->print();
        output << "Number of data points: " << strlen(evaluators[i]->getPredvideni()) << endl;
        if (dynamic_cast<AccuracyEvaluator*>(evaluators[i])) {
            output << "Prediction Accuracy: " << evaluators[i]->evaluate() << endl;
        } else if (dynamic_cast<SensitivityEvaluator*>(evaluators[i])) {
            output << "Prediction Sensitivity: " << evaluators[i]->evaluate() << endl;
        }
    }

    Evaluator* best = highestScore(evaluators, n);
    cout << "Evaluator with highest score:" << endl;
    best->print();
    output << "Evaluator with highest score:" << endl;
    if (dynamic_cast<AccuracyEvaluator*>(best)) {
        output << "Prediction Accuracy: " << best->evaluate() << endl;
    } else if (dynamic_cast<SensitivityEvaluator*>(best)) {
        output << "Prediction Sensitivity: " << best->evaluate() << endl;
    }

    for (int i = 0; i < n; i++) {
        delete evaluators[i];
    }
    delete[] evaluators;

    input.close();
    output.close();

    return 0;
}