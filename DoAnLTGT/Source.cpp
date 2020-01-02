#include "List.h"
#include <fstream>
#include <math.h>
#include <ctime>
using namespace std;

bool ascending(long long int left, long long int right) {
	return left > right;
}
bool descending(long long int left,long long int right) {
	return left < right;
}
void Menu() {
	Helpers helper;
	List A;
	// Các tham số liên quan đến vật tư
	string MaVatTu, TenVatTu, LoaiVatTu, DonViTinh, NgayNhap, NhaSanXuat;
	int SoLuong;
	long long int DonGia, ThanhTien;
	// File
	ifstream file;
	file.open("db.txt");
	// Load dữ liệu trong file vào mảng
	if (file.is_open()) {
		while (file >> MaVatTu >> TenVatTu >> LoaiVatTu >> DonViTinh >> NhaSanXuat >> SoLuong >> DonGia >> ThanhTien >> NgayNhap) {
			A.Them(MaVatTu, TenVatTu, LoaiVatTu, DonViTinh, NgayNhap, NhaSanXuat, SoLuong, DonGia, ThanhTien);
		}
	}
	else cout << "Khong the mo file du lieu";
	file.close();
	bool exit = false;
	// Hiển thị Menu
	do
	{
		cout << "1. Them vat tu vao danh sach" << endl;
		cout << "2. Hien thi danh sach cac vat tu" << endl;
		cout << "3. Xoa vat tu trong danh sach" << endl;
		cout << "4. Tim kiem vat tu trong danh sach" << endl;
		cout << "5. Sap xep vat tu trong danh sach" << endl;
		cout << "6. Thoat chuong trinh" << endl;
		cout << "____________________________________________________________" << endl;
		cout << "Hay chon cong viec:" << endl;
		//
		int menu;
		// Lựa chọn công việc
		do {
			try {
				cout << "User>";
				cin >> menu;
				if (cin.fail() || menu < 0 || menu > 6) {
					throw string("Khong hop le , vui long nhap lai! \n");
				}
				cin.clear();
				cin.ignore(10000, '\n');
				break;
			}
			catch (string error) {
				cin.clear();
				cin.ignore(10000, '\n');
				cout << error;
			}
		} while (true);
		// Xử lí Menu
		switch (menu)
		{
			case 1: // 1) Thêm vật tư ( Thêm vào mảng + file )
			{
				system("cls");
				ofstream file;
				file.open("db.txt", ios::app);
				if (file.is_open()) {
					cout << "Nhap vao thong tin vat tu can them" << endl;
					// Mã vật tư
					cout << "Nhap vao ma vat tu: ";
					getline(cin, MaVatTu);
					MaVatTu = helper.str_replace(MaVatTu, " ", "_");
					// Tên vật tư
					cout << "Nhap vao ten vat tu: ";
					getline(cin, TenVatTu);
					TenVatTu = helper.str_replace(TenVatTu, " ", "_");
					// Loại vật tư
					cout << "Nhap vao loai vat tu: ";
					getline(cin, LoaiVatTu);
					LoaiVatTu = helper.str_replace(LoaiVatTu, " ", "_");
					// Đơn vị giá thành vật tư
					cout << "Nhap vao don vi gia thanh vat tu: ";
					getline(cin, DonViTinh);
					DonViTinh = helper.str_replace(DonViTinh, " ", "_");
					// Nhà sản xuất vật tư
					cout << "Nhap vao nha san xuat vat tu: ";
					getline(cin, NhaSanXuat);
					NhaSanXuat = helper.str_replace(NhaSanXuat, " ", "_");
					// Ngày nhập
					time_t rawtime;
					struct tm* timeinfo;
					char Date[80];
					time(&rawtime);
					timeinfo = localtime(&rawtime);
					strftime(Date, 80, "%F", timeinfo); // In theo định dạng 2019-12-25
					NgayNhap = Date;
					// Số lượng vật tư
					do {
						try {
							cout << "Nhap vao so luong vat tu:";
							cin >> SoLuong;
							if (cin.fail() || SoLuong <= 0) {
								throw string("Khong hop le , vui long nhap lai! \n");
							}
							cin.clear();
							cin.ignore(10000, '\n');
							break;
						}
						catch (string error) {
							cin.clear();
							cin.ignore(10000, '\n');
							cout << error;
						}
					} while (true);
					// Đơn giá vật tư
					do {
						try {
							cout << "Nhap vao don gia vat tu:";
							cin >> DonGia;
							if (cin.fail() || DonGia < 0) {
								throw string("Khong hop le , vui long nhap lai! \n");
							}
							cin.clear();
							cin.ignore(10000, '\n');
							break;
						}
						catch (string error) {
							cin.clear();
							cin.ignore(10000, '\n');
							cout << error;
						}
					} while (true);
					// Xử lí thành tiền
					if (SoLuong <= 100) {
						ThanhTien = DonGia * SoLuong;
					}
					else if (SoLuong > 100 && SoLuong <= 200) {
						ThanhTien = round(DonGia * SoLuong * 0.9);
					}
					else {
						ThanhTien = round(DonGia * SoLuong * 0.75);
					}
					// Thêm vào file
					file << MaVatTu << " " << TenVatTu << " " << LoaiVatTu << " " << DonViTinh << " " << NhaSanXuat << " " << SoLuong << " " << DonGia << " " << ThanhTien << " " << NgayNhap << endl;
					// Thêm vào list
					A.Them(MaVatTu, TenVatTu, LoaiVatTu, DonViTinh, NgayNhap, NhaSanXuat, SoLuong, DonGia, ThanhTien);
				}
				file.close();
				break;
			}
			case 2: // 2) Hiển thị vật tư ( Hiển thị từ mảng )
			{
				system("cls");
				A.HienThiList();
				break;
			}
			case 3: // 3) Xóa vật tư ( Xóa từ mảng rồi ghi vào file )
			{
				system("cls");
				cout << "Lua chon tieu chi de xoa vat tu: " << endl;
				cout << "1. Xoa vat tu theo ma vat tu" << endl;
				cout << "2. Xoa vat tu theo ten vat tu" << endl;
				cout << "3. Xoa vat tu theo loai vat tu" << endl;
				cout << "4. Xoa vat tu co so luong lon hon 100" << endl;
				cout << "____________________________________________________________" << endl;
				int submenu2;
				// Sub menu choice 2
				do {
					try {
						cout << "User>";
						cin >> submenu2;
						if (cin.fail() || submenu2 < 0 || submenu2 > 4) {
							throw string("Khong hop le , vui long nhap lai! \n");
						}
						cin.clear();
						cin.ignore(10000, '\n');
						break;
					}
					catch (string error) {
						cin.clear();
						cin.ignore(10000, '\n');
						cout << error;
					}
				} while (true);
				switch (submenu2) {
					case 1: // 3.1) Theo mã vật tư
					{
						string Ma;
						cout << "Hay nhap vao ma vat tu ban muon xoa: ";
						getline(cin, Ma);
						Ma = helper.str_replace(Ma, " ", "_");
						A.XoaTheoMa(Ma);
						A.GhiVaoFile();
						break;
					}
					case 2: // 3.2) Theo tên vật tư
					{
						string Ten;
						cout << "Hay nhap vao ten cua vat tu ban muon xoa: ";
						getline(cin, Ten);
						Ten = helper.str_replace(Ten, " ", "_");
						A.XoaTheoTen(Ten);
						A.GhiVaoFile();
						//
						break;
					}
					case 3: // 3.3) Theo loại vật tư
					{
						string Loai;
						cout << "Hay nhap vao loai vat tu ban muon xoa: ";
						getline(cin, Loai);
						Loai = helper.str_replace(Loai, " ", "_");
						A.XoaTheoLoai(Loai);
						A.GhiVaoFile();
						//
						break;
					}
					case 4: // 3.4) Theo số lượng vật tư hơn 100
					{
						A.XoaTren100();
						A.GhiVaoFile();
						break;
					}
				}
				break;
			}
			case 4: // 4) Tìm kiếm vật tư ( Tìm kiếm trong mảng )
			{
				system("cls");
				cout << "Lua chon tieu chi de tim kiem vat tu: " << endl;
				cout << "1. Tim kiem vat tu theo ma vat tu" << endl;
				cout << "2. Tim kiem vat tu theo ten vat tu" << endl;
				cout << "3. Tim kiem vat tu theo loai vat tu" << endl;
				cout << "____________________________________________________________" << endl;
				int submenu3;
				// Sub Menu 3 Choice
				do {
					try {
						cout << "User>";
						cin >> submenu3;
						if (cin.fail() || submenu3 < 0 || submenu3 > 3) {
							throw string("Khong hop le , vui long nhap lai! \n");
						}
						cin.clear();
						cin.ignore(10000, '\n');
						break;
					}
					catch (string error) {
						cin.clear();
						cin.ignore(10000, '\n');
						cout << error;
					}
				} while (true);
				switch (submenu3) {
					case 1: // 4.1) Theo mã vật tư
					{
						string Ma;
						cout << "Hay nhap vao ma vat tu ban muon tim: ";
						getline(cin, Ma);
						Ma = helper.str_replace(Ma, " ", "_");
						A.TimKiemTheoMa(Ma);
						break;
					}
					case 2: // 4.2) Theo tên vật tư
					{
						string Ten;
						cout << "Hay nhap vao ten cua vat tu ban muon tim: ";
						getline(cin, Ten);
						Ten = helper.str_replace(Ten, " ", "_");
						A.TimKiemTheoTen(Ten);
						break;
					}
					case 3: // 4.3) Theo loại vật tư
					{
						string Loai;
						cout << "Hay nhap vao loai vat tu ban muon tim: ";
						getline(cin, Loai);
						Loai = helper.str_replace(Loai, " ", "_");
						A.TimKiemTheoLoai(Loai);
						break;
					}
				}
				break;
			}
			case 5: // 5) Sắp xếp vật tư ( Sắp xếp trong mảng rồi ghi vào file )
			{
				system("cls");
				cout << "Lua chon tieu chi can sap xep: " << endl;
				cout << "1. Sap xep vat tu theo so luong vat tu" << endl;
				cout << "2. Sap xep vat tu theo don gia vat tu" << endl;
				cout << "3. Sap xep vat tu theo thanh tien vat tu" << endl;
				cout << "____________________________________________________________" << endl;
				cout << "Hay chon cong viec:" << endl;
				int submenu4;
				// Sub menu choice 4
				do {
					try {
						cout << "User>";
						cin >> submenu4;
						if (cin.fail() || submenu4 < 0 || submenu4 > 3) {
							throw string("Khong hop le , vui long nhap lai! \n");
						}
						cin.clear();
						cin.ignore(10000, '\n');
						break;
					}
					catch (string error) {
						cin.clear();
						cin.ignore(10000, '\n');
						cout << error;
					}
				} while (true);
				switch (submenu4) {
				case 1: // 5.1) Theo số lượng
				{
					system("cls");
					cout << "Lua chon thu tu sap xep: " << endl;
					cout << "1. Theo thu tu tang dan" << endl;
					cout << "2. Theo thu tu giam dan" << endl;
					cout << "____________________________________________________________" << endl;
					cout << "Hay chon cong viec:" << endl;
					int innermenu1;
					// Inner menu choice 1
					do {
						try {
							cout << "User>";
							cin >> innermenu1;
							if (cin.fail() || innermenu1 < 0 || innermenu1 > 2) {
								throw string("Khong hop le , vui long nhap lai! \n");
							}
							cin.clear();
							cin.ignore(10000, '\n');
							break;
						}
						catch (string error) {
							cin.clear();
							cin.ignore(10000, '\n');
							cout << error;
						}
					} while (true);
					switch (innermenu1) {
						case 1: // 5.1.1) Theo thứ tự tăng dần
						{
							A.SapXepTheoSoLuong(ascending);
							A.GhiVaoFile();
							break;
						}
						case 2: // 5.1.2) Theo thứ tự giảm dần
						{
							A.SapXepTheoSoLuong(descending);
							A.GhiVaoFile();
							break;
						}
						case 3: // 5.1.3) Thoát công việc
						{
							exit = true;
							break;
						}
					}
					break;
				}
				case 2: // 5.2) Theo đơn giá
				{
					system("cls");
					cout << "Lua chon thu tu sap xep: " << endl;
					cout << "1. Theo thu tu tang dan" << endl;
					cout << "2. Theo thu tu giam dan" << endl;
					cout << "____________________________________________________________" << endl;
					cout << "Hay chon cong viec:" << endl;
					int innermenu2;
					// Inner menu choice 2
					do {
						try {
							cout << "User>";
							cin >> innermenu2;
							if (cin.fail() || innermenu2 < 0 || innermenu2 > 2) {
								throw string("Khong hop le , vui long nhap lai! \n");
							}
							cin.clear();
							cin.ignore(10000, '\n');
							break;
						}
						catch (string error) {
							cin.clear();
							cin.ignore(10000, '\n');
							cout << error;
						}
					} while (true);
					switch (innermenu2) {
						case 1: // 5.2.1) Theo thứ tự tăng dần
						{
							A.SapXepTheoDonGia(ascending);
							A.GhiVaoFile();
							break;
						}
						case 2: // 5.2.2) Theo thứ tự giảm dần
						{
							A.SapXepTheoDonGia(descending);
							A.GhiVaoFile();
							break;
						}
						case 3: // 5.2.3) Thoát công việc
						{
							exit = true;
							break;
						}
					}
					break;
				}
				case 3: // 5.3) Theo thành tiền
				{
					system("cls");
					cout << "Lua chon thu tu sap xep: " << endl;
					cout << "1. Theo thu tu tang dan" << endl;
					cout << "2. Theo thu tu giam dan" << endl;
					cout << "____________________________________________________________" << endl;
					cout << "Hay chon cong viec:" << endl;
					int innermenu3;
					// Inner menu choice 3
					do {
						try {
							cout << "User>";
							cin >> innermenu3;
							if (cin.fail() || innermenu3 < 0 || innermenu3 > 2) {
								throw string("Khong hop le , vui long nhap lai! \n");
							}
							cin.clear();
							cin.ignore(10000, '\n');
							break;
						}
						catch (string error) {
							cin.clear();
							cin.ignore(10000, '\n');
							cout << error;
						}
					} while (true);
					switch (innermenu3) {
						case 1: // 5.3.1) Theo thứ tự tăng dần
						{
							A.SapXepTheoThanhTien(ascending);
							A.GhiVaoFile();
							break;
						}
						case 2: // 5.3.2) Theo thứ tự giảm dần
						{
							A.SapXepTheoThanhTien(descending);
							A.GhiVaoFile();
							break;
						}
						case 3: // 5.3.3) Thoát công việc
						{
							exit = true;
							break;
						}
					}
					break;
				}
				}
				break;
			}
			case 6: // 6) Thoát chương trình
			{
				exit = true;
				break;
			}
		}
		if (exit == false) {
			cout << endl;
			system("pause");
			system("cls");
		}
	} while (exit == false);
}
// Hàm main
int main() {
	Menu();
	return 0;
}