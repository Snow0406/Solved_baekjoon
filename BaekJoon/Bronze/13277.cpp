#include <iostream>
#include <vector>
#include <complex>
#include <string>
#include <cmath>

using namespace std;
using Complex = complex<double>;
const double PI = acos(-1);

// 재귀를 하는게 아니라서 직접 비트 반전
void bit_reverse(vector<Complex>& v)
{
    const size_t N = v.size();
    size_t j = 0;

    for (size_t i = 1; i < N; ++i)
    {
        size_t bit = N >> 1;
        while (j & bit)
        {
            j ^= bit;
            bit >>= 1;
        }
        j ^= bit;
        if (i < j)
            swap(v[i], v[j]);
    }
}

void fft(vector<Complex>& x, bool inverse = false) {
    bit_reverse(x); // 비트 반전
    
    const size_t N = x.size();

    // Bottom-up 분할정복
    for (size_t len = 2; len <= N; len <<= 1) {

        // 단위근 계산
        // Inverse FFT일때는 각도 부호 반대
        double angle = 2 * PI / len * (inverse ? 1 : -1);
        Complex wlen(cos(angle), sin(angle));
        
        for (size_t i = 0; i < N; i += len) {
            Complex w(1); // 현재 단위근 (w^0 = 1)

            // 버터플라이 연산 수행
            for (size_t j = 0; j < len / 2; ++j) {
                Complex u = x[i + j];
                Complex v = x[i + j + len / 2] * w;
                
                x[i + j] = u + v;
                x[i + j + len / 2] = u - v; // 대칭성 활용
                w *= wlen;
            }
        }
    }

    // 만약 Inverse FFT 일때는 자릿수 나누기
    if (inverse) {
        for (Complex& val : x) {
            val /= N;
        }
    }
}

vector<int> multiply(const string& a, const string& b) {
    vector<Complex> fa(a.begin(), a.end());
    vector<Complex> fb(b.begin(), b.end());
    
    // 크기를 2의 거듭제곱으로 맞춤
    size_t n = 1;
    while (n < a.size() + b.size()) n <<= 1;
    fa.resize(n);
    fb.resize(n);
    
    // 숫자를 역순으로 배치 (낮은 자릿수가 앞에)
    for (size_t i = 0; i < a.size(); ++i) {
        fa[i] = Complex(a[a.size() - 1 - i] - '0', 0);
    }
    for (size_t i = 0; i < b.size(); ++i) {
        fb[i] = Complex(b[b.size() - 1 - i] - '0', 0);
    }
    
    // Forward FFT
    fft(fa, false);
    fft(fb, false);
    
    // 점별 곱셈
    for (size_t i = 0; i < n; ++i) {
        fa[i] *= fb[i];
    }
    
    // Inverse FFT
    fft(fa, true);
    
    // 결과 정리 및 자릿수 올림
    vector<int> result(n);
    for (size_t i = 0; i < n; ++i) {
        result[i] = round(fa[i].real());
    }
    
    // 자릿수 올림 처리
    for (size_t i = 0; i < n - 1; ++i) {
        result[i + 1] += result[i] / 10;
        result[i] %= 10;
    }
    
    // 앞의 0 제거
    while (result.size() > 1 && result.back() == 0) {
        result.pop_back();
    }
    
    return result;
}

int main()
{
    string a, b;
    cin >> a >> b;
    
    vector<int> result = multiply(a, b);
    
    for (int i = result.size() - 1; i >= 0; i--) {
        cout << result[i];
    }
    cout << "\n";
    
    return 0;
}