#include "List.h"
#include <fstream>
#include <math.h>
#include <ctime>
using namespace std;
// Hai hàm so sánh được sử dụng trong con trỏ hàm
bool ascending(int left, int right) {
	return left > right;
}
bool descending(int left, int right) {
	return left < right;
}
string str_replace(string input, string pre, string pos) {
	int length = input.size();
	int x = 0;
	string fixed;
	while (x != length) {
		string letter = input.substr(x, 1);
		if (letter == pre) {
			letter = pos;
		}
		fixed = fixed + letter;
		x++;
	}
	return fixed;
}
void Menu() {
	// Khởi tạo một List
	List A;
	// Các tham số liên quan đến vật tư
	string MaVatTu, TenVatTu, LoaiVatTu, DonViTinh, NgayNhap, NhaSanXuat;
	int SoLuong, DonGia, ThanhTien;
	// File
	ifstream file;
	file.open("db.txt");
	// Load dữ liệu trong file vào mảng
	if (file.is_open()) {
		while (file >> MaVatTu >> TenVatTu >> LoaiVatTu >> DonViTinh >> NhaSanXuat >> SoLuong >> DonGia >> ThanhTien >> NgayNhap) {
			A.Them(MaVatTu, TenVatTu, LoaiVatTu, DonViTinh, NgayNhap, NhaSanXuat, SoLuong, DonGia, ThanhTien);
		}
	}
	else cout << "Unable to open file";
	file.close();
	// Menu
	string choice;
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
		// Menu Choice
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
		//
		switch (menu)
		{
			case 1: // 1) Thêm vật tư ( Thêm vào file sau đó thêm vào list hiện tại )
			{
				system("cls");
				cout << "1. Them vat tu vao khong sap xep" << endl;
				cout << "2. Them vat tu vao co sap xep theo so luong" << endl;
				cout << "3. Thoat cong viec" << endl;
				cout << "____________________________________________________________" << endl;
				//
				int submenu1;
				do {
					try {
						cout << "User>";
						cin >> submenu1;
						if (cin.fail() || submenu1 < 0 || submenu1 > 3) {
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

				switch (submenu1) {
				case 1: // 1.1) Không sắp xếp sau khi thêm
				{
					ofstream file;
					file.open("db.txt", ios::app);
					if (file.is_open()) {
						cout << "Nhap vao thong tin vat tu can them" << endl;
						// Mã vật tư
						cout << "Nhap vao ma vat tu: ";
						getline(cin, MaVatTu);
						MaVatTu = str_replace(MaVatTu, " ", "_");
						cout << endl;
						// Tên vật tư
						cout << "Nhap vao ten vat tu: ";
						getline(cin, TenVatTu);
						TenVatTu = str_replace(TenVatTu, " ", "_");
						cout << endl;
						// Loại vật tư
						cout << "Nhap vao loai vat tu: ";
						getline(cin, LoaiVatTu);
						LoaiVatTu = str_replace(LoaiVatTu, " ", "_");
						cout << endl;
						// Đơn vị giá thành vật tư
						cout << "Nhap vao don vi gia thanh vat tu: ";
						getline(cin, DonViTinh);
						DonViTinh = str_replace(DonViTinh, " ", "_");
						cout << endl;
						// Ngày nhập
						time_t tt;
						struct tm* ti;
						time(&tt);
						ti = localtime(&tt);
						NgayNhap = str_replace(asctime(ti), " ", "_");
						NgayNhap = str_replace(NgayNhap, "\n", " ");
						// Nhà sản xuất vật tư
						cout << "Nhap vao nha san xuat vat tu: ";
						getline(cin, NhaSanXuat);
						NhaSanXuat = str_replace(NhaSanXuat, " ", "_");
						cout << endl;
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
						// Xử lí giá thành
						if (SoLuong <= 100) {
							ThanhTien = DonGia * SoLuong;
						}
						else if (SoLuong > 100 && SoLuong <= 200) {
							ThanhTien = ceilf((DonGia * SoLuong) * 0.1);
						}
						else {
							ThanhTien = ceilf((DonGia * SoLuong) * 0.2);
						}
						// Thêm vào file
						file << MaVatTu << " " << TenVatTu << " " << LoaiVatTu << " " << DonViTinh << " " << NhaSanXuat << " " << SoLuong << " " << DonGia << " " << ThanhTien << " " << NgayNhap << endl;
						// Thêm vào list
						A.Them(MaVatTu, TenVatTu, LoaiVatTu, DonViTinh, NgayNhap, NhaSanXuat, SoLuong, DonGia, ThanhTien);
					}
					file.close();
					break;
				}
				case 2: // 1.2) Sắp xếp theo số lượng sau khi thêm
				{
					cout << "Nhap vao thong tin vat tu can them" << endl;
					// Mã vật tư
					cout << "Nhap vao ma vat tu: ";
					getline(cin, MaVatTu);
					MaVatTu = str_replace(MaVatTu, " ", "_");
					cout << endl;
					// Tên vật tư
					cout << "Nhap vao ten vat tu: ";
					getline(cin, TenVatTu);
					TenVatTu = str_replace(TenVatTu, " ", "_");
					cout << endl;
					// Loại vật tư
					cout << "Nhap vao loai vat tu: ";
					getline(cin, LoaiVatTu);
					LoaiVatTu = str_replace(LoaiVatTu, " ", "_");
					cout << endl;
					// Đơn vị giá thành vật tư
					cout << "Nhap vao don vi gia thanh vat tu: ";
					getline(cin, DonViTinh);
					DonViTinh = str_replace(DonViTinh, " ", "_");
					cout << endl;
					// Ngày nhập
					time_t tt;
					struct tm* ti;
					time(&tt);
					ti = localtime(&tt);
					NgayNhap = str_replace(asctime(ti), " ", "_");
					NgayNhap = str_replace(NgayNhap, "\n", " ");
					// Nhà sản xuất vật tư
					cout << "Nhap vao nha san xuat vat tu: ";
					getline(cin, NhaSanXuat);
					NhaSanXuat = str_replace(NhaSanXuat, " ", "_");
					cout << endl;
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
					// Xử lí giá thành
					if (SoLuong <= 100) {
						ThanhTien = DonGia * SoLuong;
					}
					else if (SoLuong > 100 && SoLuong <= 200) {
						ThanhTien = ceilf((DonGia * SoLuong) * 0.1);
					}
					else {
						ThanhTien = ceilf((DonGia * SoLuong) * 0.2);
					}
					// Thêm vào list
					A.Them(MaVatTu, TenVatTu, LoaiVatTu, DonViTinh, NgayNhap, NhaSanXuat, SoLuong, DonGia, ThanhTien);
					A.SapXepTheoSoLuong(ascending);
					A.GhiVaoFile();
					break;
				}
				case 3: // 1.3) Thoát công việc
				{
					break;
				}
				}
				break;
			}
			case 2: // 2) Hiển thị vật tư ( hiển thị từ list )
			{
				system("cls");
				A.HienThiList();
				break;
			}
			case 3: // 3) Xóa vật tư ( Xóa từ list rồi ghi vào file - Chưa xong )
			{
				system("cls");
				cout << "Lua chon tieu chi de xoa vat tu: " << endl;
				cout << "1. Xoa vat tu theo ma vat tu" << endl;
				cout << "2. Xoa vat tu theo ten vat tu" << endl;
				cout << "3. Xoa vat tu theo loai vat tu" << endl;
				cout << "4. Xoa vat tu co so luong lon hon 100" << endl;
				cout << "5. Thoat cong viec" << endl;
				cout << "____________________________________________________________" << endl;
				int submenu2;
				// Sub menu choice 2
				do {
					try {
						cout << "User>";
						cin >> submenu2;
						if (cin.fail() || submenu2 < 0 || submenu2 > 5) {
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
						Ma = str_replace(Ma, " ", "_");
						A.XoaTheoMa(Ma);
						A.GhiVaoFile();
						break;
					}
					case 2: // 3.2) Theo tên vật tư
					{
						string Ten;
						cout << "Hay nhap vao ten cua vat tu ban muon xoa: ";
						getline(cin, Ten);
						Ten = str_replace(Ten, " ", "_");
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
						Loai = str_replace(Loai, " ", "_");
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
					case 5: // 3.5) Thoát công việc
					{
						break;
					}
				}
				break;
			}
			case 4: // 4) Tìm kiếm vật tư ( Tìm kiếm trong list )
			{
				system("cls");
				cout << "Lua chon tieu chi de tim kiem vat tu: " << endl;
				cout << "1. Tim kiem vat tu theo ma vat tu" << endl;
				cout << "2. Tim kiem vat tu theo ten vat tu" << endl;
				cout << "3. Tim kiem vat tu theo loai vat tu" << endl;
				cout << "4. Thoat cong viec" << endl;
				cout << "____________________________________________________________" << endl;
				int submenu3;
				// Sub Menu 3 Choice
				do {
					try {
						cout << "User>";
						cin >> submenu3;
						if (cin.fail() || submenu3 < 0 || submenu3 > 4) {
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
						Ma = str_replace(Ma, " ", "_");
						A.TimKiemTheoMa(Ma);
						break;
					}
					case 2: // 4.2) Theo tên vật tư
					{
						string Ten;
						cout << "Hay nhap vao ten cua vat tu ban muon tim: ";
						getline(cin, Ten);
						Ten = str_replace(Ten, " ", "_");
						A.TimKiemTheoTen(Ten);
						break;
					}
					case 3: // 4.3) Theo loại vật tư
					{
						string Loai;
						cout << "Hay nhap vao loai vat tu ban muon tim: ";
						getline(cin, Loai);
						Loai = str_replace(Loai, " ", "_");
						A.TimKiemTheoLoai(Loai);
						break;
					}
					case 4: // 4.4) Thoát công việc
					{
						break;
					}
				}
				break;
			}
			case 5: // 5) Sắp xếp vật tư ( Sắp xếp từ list rồi ghi list vào file )
			{
				system("cls");
				cout << "Lua chon tieu chi can sap xep: " << endl;
				cout << "1. Sap xep vat tu theo so luong vat tu" << endl;
				cout << "2. Sap xep vat tu theo don gia vat tu" << endl;
				cout << "3. Sap xep vat tu theo thanh tien vat tu" << endl;
				cout << "4. Thoat cong viec" << endl;
				cout << "____________________________________________________________" << endl;
				cout << "Hay chon cong viec:" << endl;
				int submenu4;
				// Sub menu choice 4
				do {
					try {
						cout << "User>";
						cin >> submenu4;
						if (cin.fail() || submenu4 < 0 || submenu4 > 4) {
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
					cout << "3. Thoat cong viec" << endl;
					cout << "____________________________________________________________" << endl;
					cout << "Hay chon cong viec:" << endl;
					int innermenu1;
					// Inner menu choice 1
					do {
						try {
							cout << "User>";
							cin >> innermenu1;
							if (cin.fail() || innermenu1 < 0 || innermenu1 > 3) {
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
					cout << "3. Thoat cong viec" << endl;
					cout << "____________________________________________________________" << endl;
					cout << "Hay chon cong viec:" << endl;
					int innermenu2;
					// Inner menu choice 2
					do {
						try {
							cout << "User>";
							cin >> innermenu2;
							if (cin.fail() || innermenu2 < 0 || innermenu2 > 3) {
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
					cout << "3. Thoat cong viec" << endl;
					cout << "____________________________________________________________" << endl;
					cout << "Hay chon cong viec:" << endl;
					int innermenu3;
					// Inner menu choice 3
					do {
						try {
							cout << "User>";
							cin >> innermenu3;
							if (cin.fail() || innermenu3 < 0 || innermenu3 > 3) {
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
							break;
						}
					}
					break;
				}
				case 4: // 5.4) Thoát công việc
				{
					break;
				}
				}
				break;
			}
		}
		// Xử lí tiếp tục công việc
		do {
			cout << "Ban co muon tiep tuc cong viec hay khong ( Y/N )" << endl;
			cout << "User>";
			getline(cin, choice);
		} while (choice != "Y" && choice != "N" && choice != "y" && choice != "n");
		if (choice == "Y" || choice == "y") {
			system("cls");
		}
		else {
			break;
		}
	} while (choice == "Y" || choice == "y");
}
int main() {
	Menu();
	return 0;
}