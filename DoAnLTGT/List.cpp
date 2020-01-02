#include "List.h"
Helpers helper2;
// Hàm hoán vị
void HoanVi(VatTu& VT1, VatTu& VT2) {
	VatTu temp;
	temp = VT1;
	VT1 = VT2;
	VT2 = temp;
}
// Hàm dựng
List::List()
	: PhanTu(0)
{
	this->DanhSachVatTu = new VatTu[this->PhanTu];
}
List::List(const List& L)
{
	this->PhanTu = L.PhanTu;
	this->DanhSachVatTu = new VatTu[this->PhanTu];
	for (int i = 0; i < this->PhanTu; i++) {
		*(this->DanhSachVatTu + i) = *(L.DanhSachVatTu + i);
	}
}
List::List(VatTu VT, int PhanTu)
	: PhanTu(PhanTu)
{
	// Hàm dựng đầy đủ tham số tạo ra một List gồm các đối tượng nhân viên giống nhau
	this->DanhSachVatTu = new VatTu[this->PhanTu];
	for (int i = 0; i < this->PhanTu; i++) {
		*(this->DanhSachVatTu + i) = VT;
	}
}
// Hàm hiển thị
void List::HienThiList() {
	cout << " _____________________________________________________________________________________________________________________________________________________________________________" << endl;
	cout << "|" << setw(5) << "STT" << "|";
	cout << setw(15) << "Ma Vat Tu" << "|";
	cout << setw(20) << "Ten Vat Tu" << "|";
	cout << setw(20) << "Loai Vat Tu" << "|";
	cout << setw(25) << "Nha San Xuat" << "|";
	cout << setw(10) << "So Luong" << "|";
	cout << setw(20) << "Don Gia" << "|";
	cout << setw(20) << "Thanh Tien" << "|";
	cout << setw(30) << "Ngay nhap" << "|" << endl;
	cout << "|_____|";
	cout << setw(15) << "_______________|";
	cout << setw(20) << "____________________|";
	cout << setw(20) << "____________________|";
	cout << setw(25) << "_________________________|";
	cout << setw(10) << "__________|";
	cout << setw(20) << "____________________|";
	cout << setw(20) << "____________________|";
	cout << setw(30) << "______________________________|";
	cout << endl;
 	for (int i = 0; i < this->PhanTu; i++) {
		cout << "|" << setw(5) << i + 1 << "|";
		(this->DanhSachVatTu + i)->HienThiVatTu();
		cout << "|_____|";
		cout << setw(15) << "_______________|";
		cout << setw(20) << "____________________|";
		cout << setw(20) << "____________________|";
		cout << setw(25) << "_________________________|";
		cout << setw(10) << "__________|";
		cout << setw(20) << "____________________|";
		cout << setw(20) << "____________________|";
		cout << setw(30) << "______________________________|";
		cout << endl;
	}
}
// Hàm thêm
void List::Them(string MaVatTu, string TenVatTu, string LoaiVatTu, string DonViTinh, string NgayNhap, string NhaSanXuat, int SoLuong, long long int DonGia, long long ThanhTien) {
	this->PhanTu++;
	// Khởi tạo một nhân viên mới thông qua hàm dựng đầy đủ tham số
	VatTu VatTuMoi(MaVatTu, TenVatTu, LoaiVatTu, DonViTinh, NgayNhap, NhaSanXuat, SoLuong, DonGia, ThanhTien);
	// Chưa có phần tử nào trong list
	if (this->PhanTu == 1) {
		delete[]this->DanhSachVatTu; // Hủy mảng rỗng khởi tạo ban đầu
		// Khởi tạo lại một mảng mới có 1 phần tử
		this->DanhSachVatTu = new VatTu[this->PhanTu];
		*(this->DanhSachVatTu) = VatTuMoi;
	}
	// Đã tồn tại các phần tử trong list
	else {
		// Khởi tạo một mảng mới để chứa các phần tử List
		VatTu* MangMoi = new VatTu[this->PhanTu];
		int j = 0;
		for (int i = 0; i < this->PhanTu; i++) {
			if (i != this->PhanTu - 1) {
				*(MangMoi + i) = *(this->DanhSachVatTu + i);
			}
			else {
				*(MangMoi + i) = VatTuMoi;
			}
		}
		// Khởi tạo một list nhân viên mới để copy từ mảng mới qua
		delete[]this->DanhSachVatTu;
		this->DanhSachVatTu = new VatTu[this->PhanTu];
		for (int i = 0; i < this->PhanTu; i++) {
			*(this->DanhSachVatTu + i) = *(MangMoi + i);
		}
		delete[]MangMoi;
	}
}

// Hàm xóa
void List::XoaTheoMa(string Ma) {
	int DeleteCount = 0;
	for (int i = 0; i < this->PhanTu; i++) {
		// Đếm số phần tử phải xóa
		if ((this->DanhSachVatTu + i)->LayMaVatTu() == Ma) {
			DeleteCount++;
		}
	}
	if (DeleteCount == 0) {
		cout << endl << endl << "Khong tim thay vat tu nao co ma '" << helper2.str_replace(Ma, "_", " ") << "' de xoa" << endl;
	}
	else {
		cout << "Da xoa " << DeleteCount << " vat tu" << endl;
		// Khởi tạo một mảng mới để chứa các phần tử List không bao gồm các phần tử bị xóa
		VatTu* MangMoi = new VatTu[(this->PhanTu) - DeleteCount];
		int j = 0;
		for (int i = 0; i < this->PhanTu; i++) {
			if ((this->DanhSachVatTu + i)->LayMaVatTu() != Ma) {
				*(MangMoi + j) = *(this->DanhSachVatTu + i);
			}
			else {
				j--;
			}
			j++;
		}
		delete[]this->DanhSachVatTu;
		this->PhanTu = this->PhanTu - DeleteCount;
		DanhSachVatTu = new VatTu[this->PhanTu];
		for (int i = 0; i < this->PhanTu; i++) {
			*(this->DanhSachVatTu + i) = *(MangMoi + i);
		}
		delete[] MangMoi;
	}
}
void List::XoaTheoTen(string Ten) {
	int DeleteCount = 0;
	for (int i = 0; i < this->PhanTu; i++) {
		// Đếm số phần tử phải xóa
		if ((this->DanhSachVatTu + i)->LayTenVatTu() == Ten) {
			DeleteCount++;
		}
	}
	if (DeleteCount == 0) {
		cout << endl << endl << "Khong tim thay vat tu nao co ten '" << helper2.str_replace(Ten, "_", " ") << "' de xoa" << endl;
	}
	else {
		cout << "Da xoa " << DeleteCount << " vat tu" << endl;
		// Khởi tạo một mảng mới để chứa các phần tử List không bao gồm các phần tử bị xóa
		VatTu* MangMoi = new VatTu[(this->PhanTu) - DeleteCount];
		int j = 0;
		for (int i = 0; i < this->PhanTu; i++) {
			if ((this->DanhSachVatTu + i)->LayTenVatTu() != Ten) {
				*(MangMoi + j) = *(this->DanhSachVatTu + i);
			}
			else {
				j--;
			}
			j++;
		}
		delete[]this->DanhSachVatTu;
		this->PhanTu = this->PhanTu - DeleteCount;
		DanhSachVatTu = new VatTu[this->PhanTu];
		for (int i = 0; i < this->PhanTu; i++) {
			*(this->DanhSachVatTu + i) = *(MangMoi + i);
		}
		delete[] MangMoi;
	}
}
void List::XoaTheoLoai(string Loai) {
	int DeleteCount = 0;
	for (int i = 0; i < this->PhanTu; i++) {
		// Đếm số phần tử phải xóa
		if ((this->DanhSachVatTu + i)->LayLoaiVatTu() == Loai) {
			DeleteCount++;
		}
	}
	if (DeleteCount == 0) {
		cout << endl << endl << "Khong tim thay vat tu nao co loai '" << helper2.str_replace(Loai, "_", " ") << "' de xoa" << endl;
	}
	else {
		cout << "Da xoa " << DeleteCount << " vat tu" << endl;
		// Khởi tạo một mảng mới để chứa các phần tử List không bao gồm các phần tử bị xóa
		VatTu* MangMoi = new VatTu[(this->PhanTu) - DeleteCount];
		int j = 0;
		for (int i = 0; i < this->PhanTu; i++) {
			if ((this->DanhSachVatTu + i)->LayLoaiVatTu() != Loai) {
				*(MangMoi + j) = *(this->DanhSachVatTu + i);
			}
			else {
				j--;
			}
			j++;
		}
		delete[]this->DanhSachVatTu;
		this->PhanTu = this->PhanTu - DeleteCount;
		DanhSachVatTu = new VatTu[this->PhanTu];
		for (int i = 0; i < this->PhanTu; i++) {
			*(this->DanhSachVatTu + i) = *(MangMoi + i);
		}
		delete[] MangMoi;
	}
}
void List::XoaTren100() {
	int DeleteCount = 0;
	for (int i = 0; i < this->PhanTu; i++) {
		// Đếm số phần tử phải xóa
		if ((this->DanhSachVatTu + i)->LaySoLuong() > 100) {
			DeleteCount++;
		}
	}
	if (DeleteCount == 0) {
		cout << "Khong co phan tu nao phu hop voi so luong lon hon 100 de xoa" << endl;
	}
	else {
		cout << "Da xoa " << DeleteCount << " vat tu" << endl;
		// Khởi tạo một mảng mới để chứa các phần tử List không bao gồm các phần tử bị xóa
		VatTu* MangMoi = new VatTu[(this->PhanTu) - DeleteCount];
		int j = 0;
		for (int i = 0; i < this->PhanTu; i++) {
			if ((this->DanhSachVatTu + i)->LaySoLuong() <= 100) {
				*(MangMoi + j) = *(this->DanhSachVatTu + i);
			}
			else {
				j--;
			}
			j++;
		}
		delete[]this->DanhSachVatTu;
		this->PhanTu = this->PhanTu - DeleteCount;
		DanhSachVatTu = new VatTu[this->PhanTu];
		for (int i = 0; i < this->PhanTu; i++) {
			*(this->DanhSachVatTu + i) = *(MangMoi + i);
		}
		delete[] MangMoi;
	}
}
// Hàm tìm kiếm
void List::TimKiemTheoMa(string Ma) {
	int found = 0;
	cout << " _____________________________________________________________________________________________________________________________________________________________________________" << endl;
	cout << "|" << setw(5) << "STT" << "|";
	cout << setw(15) << "Ma Vat Tu" << "|";
	cout << setw(20) << "Ten Vat Tu" << "|";
	cout << setw(20) << "Loai Vat Tu" << "|";
	cout << setw(25) << "Nha San Xuat" << "|";
	cout << setw(10) << "So Luong" << "|";
	cout << setw(20) << "Don Gia" << "|";
	cout << setw(20) << "Thanh Tien" << "|";
	cout << setw(30) << "Ngay nhap" << "|" << endl;
	cout << "|_____|";
	cout << setw(15) << "_______________|";
	cout << setw(20) << "____________________|";
	cout << setw(20) << "____________________|";
	cout << setw(25) << "_________________________|";
	cout << setw(10) << "__________|";
	cout << setw(20) << "____________________|";
	cout << setw(20) << "____________________|";
	cout << setw(30) << "______________________________|";
	cout << endl;
	for (int i = 0; i < this->PhanTu; i++) {
		if ((this->DanhSachVatTu + i)->LayMaVatTu() == Ma) {
			cout << "|" << setw(5) << i + 1 << "|";
			(this->DanhSachVatTu + i)->HienThiVatTu();
			cout << "|_____|";
			cout << setw(15) << "_______________|";
			cout << setw(20) << "____________________|";
			cout << setw(20) << "____________________|";
			cout << setw(25) << "_________________________|";
			cout << setw(10) << "__________|";
			cout << setw(20) << "____________________|";
			cout << setw(20) << "____________________|";
			cout << setw(30) << "______________________________|";
			cout << endl;
			found++;
		}
	}
	if (found == 0) {
		system("cls");
		cout << endl << endl << "Khong tim thay vat tu nao co ma '" << helper2.str_replace(Ma, "_", " ") << "'" << endl;
	}
	else {
		cout << "So vat tu tim duoc: " << found << " vat tu" << endl;
	}
}
void List::TimKiemTheoTen(string Ten) {
	int found = 0;
	cout << " _____________________________________________________________________________________________________________________________________________________________________________" << endl;
	cout << "|" << setw(5) << "STT" << "|";
	cout << setw(15) << "Ma Vat Tu" << "|";
	cout << setw(20) << "Ten Vat Tu" << "|";
	cout << setw(20) << "Loai Vat Tu" << "|";
	cout << setw(25) << "Nha San Xuat" << "|";
	cout << setw(10) << "So Luong" << "|";
	cout << setw(20) << "Don Gia" << "|";
	cout << setw(20) << "Thanh Tien" << "|";
	cout << setw(30) << "Ngay nhap" << "|" << endl;
	cout << "|_____|";
	cout << setw(15) << "_______________|";
	cout << setw(20) << "____________________|";
	cout << setw(20) << "____________________|";
	cout << setw(25) << "_________________________|";
	cout << setw(10) << "__________|";
	cout << setw(20) << "____________________|";
	cout << setw(20) << "____________________|";
	cout << setw(30) << "______________________________|";
	cout << endl;
	for (int i = 0; i < this->PhanTu; i++) {
		if ((this->DanhSachVatTu + i)->LayTenVatTu() == Ten) {
			cout << "|" << setw(5) << i + 1 << "|";
			(this->DanhSachVatTu + i)->HienThiVatTu();
			cout << "|_____|";
			cout << setw(15) << "_______________|";
			cout << setw(20) << "____________________|";
			cout << setw(20) << "____________________|";
			cout << setw(25) << "_________________________|";
			cout << setw(10) << "__________|";
			cout << setw(20) << "____________________|";
			cout << setw(20) << "____________________|";
			cout << setw(30) << "______________________________|";
			cout << endl;
			found++;
		}
	}
	if (found == 0) {
		system("cls");
		cout << endl << endl << "Khong tim thay vat tu nao co ten '" << helper2.str_replace(Ten, "_", " ") << "'" << endl;
	}
	else {
		cout << "So vat tu tim duoc: " << found << " vat tu" << endl;
	}
}
void List::TimKiemTheoLoai(string Loai) {
	int found = 0;
	cout << " _____________________________________________________________________________________________________________________________________________________________________________" << endl;
	cout << "|" << setw(5) << "STT" << "|";
	cout << setw(15) << "Ma Vat Tu" << "|";
	cout << setw(20) << "Ten Vat Tu" << "|";
	cout << setw(20) << "Loai Vat Tu" << "|";
	cout << setw(25) << "Nha San Xuat" << "|";
	cout << setw(10) << "So Luong" << "|";
	cout << setw(20) << "Don Gia" << "|";
	cout << setw(20) << "Thanh Tien" << "|";
	cout << setw(30) << "Ngay nhap" << "|" << endl;
	cout << "|_____|";
	cout << setw(15) << "_______________|";
	cout << setw(20) << "____________________|";
	cout << setw(20) << "____________________|";
	cout << setw(25) << "_________________________|";
	cout << setw(10) << "__________|";
	cout << setw(20) << "____________________|";
	cout << setw(20) << "____________________|";
	cout << setw(30) << "______________________________|";
	cout << endl;
	for (int i = 0; i < this->PhanTu; i++) {
		if ((this->DanhSachVatTu + i)->LayLoaiVatTu() == Loai) {
			cout << "|" << setw(5) << i + 1 << "|";
			(this->DanhSachVatTu + i)->HienThiVatTu();
			cout << "|_____|";
			cout << setw(15) << "_______________|";
			cout << setw(20) << "____________________|";
			cout << setw(20) << "____________________|";
			cout << setw(25) << "_________________________|";
			cout << setw(10) << "__________|";
			cout << setw(20) << "____________________|";
			cout << setw(20) << "____________________|";
			cout << setw(30) << "______________________________|";
			cout << endl;
			found++;
		}
	}
	if (found == 0) {
		system("cls");
		cout << endl << endl << "Khong tim thay vat tu nao co loai '" << helper2.str_replace(Loai, "_", " ") << "'" << endl;
	}
	else {
		cout << "So vat tu tim duoc: " << found << " vat tu" << endl;
	}
}

// Hàm sắp xếp
void List::SapXepTheoDonGia(bool (*Func)(long long int, long long int)) {
	// Trường hợp list không có phần tử nào để sắp xếp
	if (this->PhanTu == 0) {
		cout << "Khong co phan tu nao de sap xep";
	}
	else {
		for (int i = 0; i < this->PhanTu-1; i++) {
			for (int j = i + 1; j < this->PhanTu; j++) {
				if (Func((this->DanhSachVatTu + i)->LayDonGia(), (this->DanhSachVatTu + j)->LayDonGia())) {
					HoanVi(*(this->DanhSachVatTu+i),*(this->DanhSachVatTu+j));
				}
			}
		}
	}
}
void List::SapXepTheoThanhTien(bool(*Func)(long long int, long long int)) {
	// Trường hợp list không có phần tử nào để sắp xếp
	if (this->PhanTu == 0) {
		cout << "Khong co phan tu nao de sap xep";
	}
	else {
		for (int i = 0; i < this->PhanTu - 1; i++) {
			for (int j = i + 1; j < this->PhanTu; j++) {
				if (Func((this->DanhSachVatTu + i)->LayThanhTien(), (this->DanhSachVatTu + j)->LayThanhTien())) {
					HoanVi(*(this->DanhSachVatTu + i), *(this->DanhSachVatTu + j));
				}
			}
		}
	}
}
void List::SapXepTheoSoLuong(bool(*Func)(long long int, long long int)) {
	// Trường hợp list không có phần tử nào để sắp xếp
	if (this->PhanTu == 0) {
		cout << "Khong co phan tu nao de sap xep";
	}
	else {
		for (int i = 0; i < this->PhanTu - 1; i++) {
			for (int j = i + 1; j < this->PhanTu; j++) {
				if (Func((this->DanhSachVatTu + i)->LaySoLuong(), (this->DanhSachVatTu + j)->LaySoLuong())) {
					HoanVi(*(this->DanhSachVatTu + i), *(this->DanhSachVatTu + j));
				}
			}
		}
	}
}

// Hàm hủy
List::~List() {
	delete[]this->DanhSachVatTu;
}
// Hàm ghi vào file
void List::GhiVaoFile() {
	ofstream newFile;
	ifstream file;
	newFile.open("newdb.txt");
	if (newFile.is_open()) {
		for (int i = 0; i < this->PhanTu; i++) {
			newFile << (this->DanhSachVatTu + i)->LayMaVatTu() << " ";
			newFile << (this->DanhSachVatTu + i)->LayTenVatTu() << " ";
			newFile << (this->DanhSachVatTu + i)->LayLoaiVatTu() << " ";
			newFile << (this->DanhSachVatTu + i)->LayDonViTinh() << " ";
			newFile << (this->DanhSachVatTu + i)->LayNhaSanXuat() << " ";
			newFile << (this->DanhSachVatTu + i)->LaySoLuong() << " ";
			newFile << (this->DanhSachVatTu + i)->LayDonGia() << " ";
			newFile << (this->DanhSachVatTu + i)->LayThanhTien() << " ";
			newFile << (this->DanhSachVatTu + i)->LayNgayNhap();
			newFile << endl;
		}
	}
	newFile.close();
	remove("db.txt");
	rename("newdb.txt", "db.txt");
}

// Hàm global
int HienThiElement(List& p) {
	return p.PhanTu;
}