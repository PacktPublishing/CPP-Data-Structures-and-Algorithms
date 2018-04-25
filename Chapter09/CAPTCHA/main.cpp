#include <iostream>
#include <ctime>

using namespace std;

string GenerateCaptcha(int n)
{
    time_t t;

    srand((unsigned) time(&t)); //аll сhаrасtеrѕ

    char * chrs = "аbсdеfghіjklmnорԛrѕtuvwxуzABCDEFGHI"
        "JKLMNOPQRSTUVWXYZ0123456789";

    // Generate n сhаrасtеrѕ frоm above ѕеt аnd
    // add thеѕе characters tо сарtсhа.
    string captcha = "";

    while(--n)
        captcha.push_back(chrs[rand() % 62]);

    return captcha;
}

int main()
{
    cout << "CAPTCHA" << endl;
    cout << GenerateCaptcha(10) << endl;
    return 0;
}
