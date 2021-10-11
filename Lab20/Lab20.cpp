#include <iostream>
#include <vector>

using namespace std;

void zd1() {

    int n;

    cout << "Enter array size : ";

    cin >> n;

    vector<int> A(n);
    vector<int> B;
    vector<int> C;

    cout << "Enter elements array :";

    for (int i = 0; i < n; i++) {

        cin >> A[i];

    }

    int el_l = A[0], len_l = 1;

    for (int i = 1; i < n; i++) {

        if (A[i] == el_l) {
            len_l++;
        }
        else {

            B.push_back(len_l);
            C.push_back(el_l);

            len_l = 1;
            el_l = A[i];

        }

    }

    B.push_back(len_l);
    C.push_back(el_l);

    cout << "Print arrays  C and B ? Y/N :";
    string s;

    cin >> s;

    if (s == "Y") {

        cout << "Array B : ";

        for (int i = 0; i < B.size(); i++) {
            cout << B[i] << " ";
        }

        cout << endl;

        cout << "Array C : ";

        for (int i = 0; i < C.size(); i++) {
            cout << C[i] << " ";
        }


    }
    else {
        cout << "OK";
    }

    return;

}

void zd2() {

    int n, l;

    cout << "Enter l :";

    cin >> l;

    cout << "Enter array size : ";

    cin >> n;

    vector<int> A(n);

    cout << "Enter elements array :";

    for (int i = 0; i < n; i++) {

        cin >> A[i];

    }

    int el_l = A[0], len_l = 1, it1 = 0, it2 = 0;

    for (int i = 1; i < A.size(); i++) {

        if (A[i] == el_l) {

            len_l++;
            it2++;

        }
        else {

            if (len_l > l) {

                A.erase(A.begin() + it1, A.begin() + it2 + 1);

                A.insert(A.begin() + it1, 0);

                i = it1 + 1;

                el_l = A[i];
                len_l = 1;
                it2 = it1 + 1;

            }
            else {

                el_l = A[i];
                len_l = 1;

                it1 = i;
                it2 = i;

            }

        }

    }

    if (len_l > l) {
        A.erase(A.begin() + it1, A.begin() + it2 + 1);

        A.insert(A.begin() + it1, 0);
    }

    cout << "Print array A : Y/N ? ";

    string s;

    cin >> s;

    if (s == "Y") {

        cout << "Array A : ";

        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }

    }
    else {
        cout << "OK";
    }


    return;

}

void zd3() {

    int n, k;

    cout << "Enter k : ";

    cin >> k;

    cout << "Enter array size : ";

    cin >> n;

    vector<int> A(n);

    cout << "Enter elements array :";

    for (int i = 0; i < n; i++) {

        cin >> A[i];

    }

    int el_l = A[0], cnt = 1, it1_k, it2_k, it1_l, it2_l, el_k, it1 = 0, it2 = 0;
    bool fl = false;

    for (int i = 1; i < n; i++) {

        if (A[i] == el_l) {

            it2++;

        }
        else {

            if (cnt == k && fl == false) {

                it1_k = it1;
                it2_k = it2;
                el_k = el_l;

                it1 = i;
                it2 = i;

                el_l = A[i];

                fl = true;

            }
            else {
                cnt++;

                it1 = i;
                it2 = i;

                el_l = A[i];

            }

        }


    }

    it1_l = it1;
    it2_l = it2;

    A.erase(A.begin() + it1_l, A.begin() + it2_l + 1);
    A.insert(A.begin() + it1_l, it2_k - it1_k + 1, el_k);

    A.erase(A.begin() + it1_k, A.begin() + it2_k + 1);
    A.insert(A.begin() + it1_k, it2_l - it1_l + 1, el_l);

    cout << "Print array A : Y/N ? ";

    string s;

    cin >> s;

    if (s == "Y") {

        for (int i = 0; i < A.size(); i++) {

            cout << A[i] << " ";

        }

    }
    else {
        cout << "OK";
    }

    return;

}

void zd4() {

    cout << "Enter the number of points : ";

    int n, x, y , x_max = 0 , y_min = 0 , g_max = 0 , g;

    cin >> n;

    cout << "Enter points : ";

    for (int i = 0; i < n; i++) {

        cin >> x >> y;

        if (x >= 0 && y <= 0) {
            g = sqrt(x * x + y * y);

            if (g >= g_max) {
                x_max = x;
                y_min = y;
                g_max = g;
            }
        }

    }

    cout << "Print point ? Y/N : ";

    string s;

    cin >> s;

    if (s == "Y") {
        cout << x_max << " " << y_min << endl;
    }

    return;

}

void zd5() {

    cout << "Enter the number of points :";

    int n , x , y;
    bool fl = true;

    cin >> n;

    vector<pair<int, int> > A;

    cout << "Enter points : ";

    for (int i = 0; i < n; i++) {

        cin >> x >> y;
        fl = true;

        for (int j = 0; j < A.size(); j++) {

            if (A[j].second == y && A[j].first == x) {
                fl = false;
                break;
            }

        }

        if (fl) {
            A.push_back(make_pair(x, y));
        }

    }

    int c1 , c2 , c3 ;
    double max_P = 0, l1, l2, l3;

    for (int i = 0; i < A.size(); i++) {

        for (int j = i + 1; j < A.size(); j++) {

            for (int g = j + 1; g < A.size(); g++) {

                l1 = sqrt(pow(A[i].first - A[j].first, 2) + pow(A[i].second - A[j].second, 2));
                l2 = sqrt(pow(A[j].first - A[g].first, 2) + pow(A[j].second - A[g].second, 2));
                l3 = sqrt(pow(A[g].first - A[i].first, 2) + pow(A[g].second - A[i].second, 2));

                if (l1 + l2 + l3 > max_P) {
                    max_P = l1 + l2 + l3;
                    c1 = i; c2 = j; c3 = g;
                }
            }

        }

    }

    cout << "Maximum perimeter = " << max_P << endl;
    cout << "Point 1 : " << A[c1].first << " " << A[c1].second << endl;
    cout << "Point 2 : " << A[c2].first << " " << A[c2].second << endl;
    cout << "Point 3 : " << A[c3].first << " " << A[c3].second << endl;

    return;

}

int main()
{

    zd5();

}
