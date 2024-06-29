#include <iostream>
#include <vector>
using namespace std;

template<typename T>

class Matrix{
public:

    Matrix(size_t numberOfRows = 0, size_t numberOfColumns = 0): nRow(numberOfRows), nColumn(numberOfColumns), mtrx(nRow, vector<T>(nColumn, 0)) {
    }

    size_t getRows() { return nRow; }
    size_t getColumns() { return nColumn; }


    void getMatrix() {
        for (auto& element1 : mtrx) {
            for (auto& element2 : element1) {
                cout << element2 << '\t';
            }
            cout << endl;
        }
    }

    void Randomize() {
        for (auto& row : mtrx) {
            for (auto& col : row) {
                col = rand() % 10;
            }
        }
    }

    T&  operator() (size_t i, size_t j){
        return mtrx.at(i).at(j);
    }

    Matrix<T> operator*(const Matrix<T>& B) {
        Matrix<T> tmp{this->nRow, B.nColumn};

        for (size_t i = 0; i < tmp.nRow; i++) {
            for (size_t j = 0; j < tmp.nColumn; j++) {
                tmp(i, j) = 0;
                for(size_t k = 0; k < this->nColumn; k++ ){
                    tmp(i, j) += this->operator()(i, k) * B.mtrx.at(k).at(j);
                }
            }
        }
        return tmp;
    }
    
    Matrix<T> operator+(const Matrix<T>& B) {
        Matrix<T> tmp(this->nRow, this->nColumn);

        for (size_t i = 0; i < tmp.nRow; i++) {
            for (size_t j = 0; j < tmp.nColumn; j++) {
                tmp(i, j) = this->operator()(i,j)+B.mtrx.at(i).at(j);
            }
        }
        return tmp;
    }


private:

    size_t nRow, nColumn;
    vector<vector<T>> mtrx;

};




int main()
{
    Matrix<int> a(3, 4);
    Matrix<int> b(4, 1);

    a.Randomize();
    b.Randomize();

    Matrix<int> c;

    c = a*b;



    cout << "----------------------------------------" << endl;
    a.getMatrix();
    cout << "----------------------------------------" << endl;
    b.getMatrix();
    cout << "----------------------------------------" << endl;
    c.getMatrix();
    cout << "----------------------------------------" << endl;
    



}
