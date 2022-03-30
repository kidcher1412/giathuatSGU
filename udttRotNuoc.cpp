#include <bits/stdc++.h> 
#define pii pair<int, int> // Ghep hai doi tuong mang gia tri integer
#define mp make_pair 
using namespace std; 

bool timDuoc = false; 
  
int BFS(int a, int b, int c) 
{ 
    map<pii, int> m; // Map de luu tru danh sach cac trang thai, moi trang thai duoc danh dau gia tri nhi phan xem da duoc duyet qua hay chua
   
    
    vector<pii> duongdi;  // Mang luu duong di
  
    queue<pii> q; // Hang doi giup duy tri trang thai
    q.push({ 0, 0 }); // Khoi tao trang thai ban dau: ca hai binh deu trong roi day vao hang doi
  
    while (!q.empty()) { 
  
        pii u = q.front(); // Trang thai hien tai duoc gan bang phan tu dau tien cua hang doi
  
        q.pop(); // Sau khi lay ra thi xoa trang thai da lay ra
  
        // Neu trang thai da duoc duyet qua thi quay lai duyet den trang thai tiep theo
        if (m[{ u.first, u.second }] == 1) 
            continue; 
  
        // Duyet den trang thai tiep theo neu luong nuoc khong nam trong kha nang chua cua binh
        if ((u.first > a || u.second > b || u.first < 0 || u.second < 0)) 
            continue; 
  
        // Them vao mang buoc tiep theo
        duongdi.push_back({ u.first, u.second }); 
         
        m[{ u.first, u.second }] = 1; // Danh dau trang thai hien tai la da duyet
  
        // Neu mot trong hai binh dat gia tri can tim
        if (u.first == c || u.second == c) { 
            timDuoc = true; 
//            if (u.first == c) { 
//                if (u.second != 0) 
//                    duongdi.push_back({ u.first, 0 }); // Them trang thai cuoi vao mang
//            } 
//            else { 
//                if (u.first != 0) 
//                    duongdi.push_back({ 0, u.second }); // Them trang thai cuoi vao mang
//            } 
  
            // Hien thi duong di
            int sz = duongdi.size(); 
            cout << "Duong di tu trang thai ban dau toi trang thai cuoi cung :\n"; 
            for (int i = 0; i < sz; i++) 
                cout << "(" << duongdi[i].first << ", " << duongdi[i].second << ")\n"; 
            break; 
        } 
  
        // Neu khong tim duoc trang thai cuoi, ta su dung trang thai trung gian
        q.push({ u.first, b }); // Do day binh 2
        q.push({ a, u.second }); // Do day binh 1
  
        for (int t = 0; t <= max(a, b); t++) { 
  
            // Do luong nuoc t tu binh 2 sang binh 1
            int d = u.first + t; 
            int e = u.second - t; 
  
            // Them trang thai vao hang doi neu binh 1 day va binh 2 khong trong
            if (d == a || (e == 0 && e >= 0)) 
                q.push({ d, e }); 
  
            // Do luong nuoc t tu binh 1 sang binh 2
            d = u.first - t; 
            e = u.second + t; 
  
            // Them trang thai vao hang doi neu binh 2 day va binh 1 khong trong
            if ((d == 0 && d >= 0) || e == b) 
                q.push({ d, e }); 
        } 
        q.push({ a, 0 }); // Them trang thai binh 1 day, binh 2 trong
        q.push({ 0, b }); // Them trang thai binh 1 trong, binh 2 day
    } 
	if(!timDuoc) cout<<"Khong tim duoc!";
} 
   
int main() 
{ 		
	BFS(10, 3, 2 ); 	    
    return 0; 
} 
