#include <bits/stdc++.h>
using namespace std;

int main(){

    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> sum_array(N);
    vector<int> c_array(N);
    vector<int> ans_array(N);
    int i;
    int temp = 0;
    int sum = 0;
    int c_temp = 0;
    int sum_buf = 0;
    
    //  入力と同じ数値の回数を記録する配列を確保
    for (i=0; i<N; i++){
        cin >> A.at(i);
        sum_array.at(A.at(i))++;
    }

    //  組み合わせ数の配列を確保し、組み合わせ数の総和を計算
    for (i=0; i<N; i++){
        if (sum_array.at(i)<2){
            c_array.at(i) = 0;
        }
        else{
            c_array.at(i) = (sum_array.at(i)*(sum_array.at(i)-1))/2;
        }
        sum += c_array.at(i);
    }

    //  ここの処理が異なる
    for (i=0; i<N; i++){
        sum_buf = sum;
        temp = sum_array.at(i) - 1;
        if (temp<2){
            c_temp = 0;
        }
        else{
            c_temp = ((temp)*(temp-1))/2;
        }
        sum_buf -= c_array.at(i) - c_temp;
        ans_array.at(i) = sum_buf;
    }

    cout << "---sum_array--" << endl; 
    for (i=0; i<N; i++){
        cout << sum_array.at(i) << endl;
    }
    cout << "sum = " << sum << endl;

    for (i=0; i<N; i++){
        cout << ans_array.at(i) << endl;
    }

    return 0;
}