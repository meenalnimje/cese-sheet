// #include <iostream>
// #include <vector>
// #include <cmath>
// using namespace std;

// class rectangle
// {
// public:
//     int x1, x2, y1, y2;
//     rectangle() {}
//     rectangle(int x1, int y1, int x2, int y2)
//     {
//         this->x1 = x1;
//         this->y1 = y1;
//         this->x2 = x2;
//         this->y2 = y2;
//     }
// };

// long long int totalArea(int n, rectangle r[])
// {
//     long long totalarea = 0;

//     for (int i = 0; i < n; i++)
//     {
//         int x = abs(r[i].x2 - r[i].x1);
//         int y = abs(r[i].y2 - r[i].y1);
//         totalarea += 1LL * x * y;
//     }

//     long long overlaparea = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             int overlap_x1 = max(r[i].x1, r[j].x1);
//             int overlap_y1 = max(r[i].y1, r[j].y1);
//             int overlap_x2 = min(r[i].x2, r[j].x2);
//             int overlap_y2 = min(r[i].y2, r[j].y2);

//             if (overlap_x1 < overlap_x2 && overlap_y1 < overlap_y2)
//             {
//                 int width = overlap_x2 - overlap_x1;
//                 int height = overlap_y2 - overlap_y1;
//                 overlaparea += 1LL * width * height;
//             }
//         }
//     }
//     cout << totalarea << endl;
//     cout << overlaparea << endl;

//     return totalarea - overlaparea;
// }

// int main()
// {
//     int n;
//     cin >> n;
//     rectangle r[n];

//     for (int i = 0; i < n; i++)
//     {
//         int x1, y1, x2, y2;
//         cin >> x1 >> y1 >> x2 >> y2;
//         r[i] = rectangle(x1, y1, x2, y2);
//     }

//     cout << totalArea(n, r);
//     return 0;
// }
