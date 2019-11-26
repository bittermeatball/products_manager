#include "List.h"
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
	for (int i = 0; i < this->PhanTu; i++) {
		cout << "Thong tin nhan vien thu " << i + 1 << " la: " << endl;
		(this->DanhSachVatTu + i)->HienThiVatTu();
	}
}
// Hàm thêm
void List::Them(string MaVatTu, string TenVatTu, string LoaiVatTu, string DonViTinh, string NgayNhap, string NhaSanXuat, int SoLuong, int DonGia, int ThanhTien, int vitri) {
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
			// Tại điểm cần chèn, ta giảm chỉ số j của List để nó tiếp tục copy phần tử kế tiếp từ List vào mảng mới
			if (i == vitri) {
				*(MangMoi + i) = VatTuMoi;
				j--;
			}
			else {
				if (j < this->PhanTu - 1) {
					*(MangMoi + i) = *(this->DanhSachVatTu + j);
				}
			}
			j++;
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

}
void List::XoaTheoTen(string Ten) {

}
void List::XoaTheoLoai(string Loai) {

}

// Hàm tìm kiếm
void List::TimKiemTheoMa(string Ma) {
	int found = 0;
	for (int i = 0; i < this->PhanTu; i++) {
		if ((this->DanhSachVatTu + i)->LayMaVatTu() == Ma) {
			(this->DanhSachVatTu + i)->HienThiVatTu();
			found++;
		}
	}
	if (found == 0) {
		cout << "Khong tim thay vat tu nao co ma da nhap" << endl;
	}
	else {
		cout << "So vat tu tim duoc: " << found << " vat tu" << endl;
	}
}
void List::TimKiemTheoTen(string Ten) {
	int found = 0;
	for (int i = 0; i < this->PhanTu; i++) {
		if ((this->DanhSachVatTu + i)->LayTenVatTu() == Ten) {
			(this->DanhSachVatTu + i)->HienThiVatTu();
			found++;
		}
	}
	if (found == 0) {
		cout << "Khong tim thay vat tu nao co ma da nhap" << endl;
	}
	else {
		cout << "So vat tu tim duoc: " << found << " vat tu" << endl;
	}
}
void List::TimKiemTheoLoai(string Loai) {
	int found = 0;
	for (int i = 0; i < this->PhanTu; i++) {
		if ((this->DanhSachVatTu + i)->LayLoaiVatTu() == Loai) {
			(this->DanhSachVatTu + i)->HienThiVatTu();
			found++;
		}
	}
	if (found == 0) {
		cout << "Khong tim thay vat tu nao co ma da nhap" << endl;
	}
	else {
		cout << "So vat tu tim duoc: " << found << " vat tu" << endl;
	}
}

// Hàm sắp xếp
void HoanVi(VatTu& VT1, VatTu& VT2) {
	VatTu temp = VT1;
	VT1 = VT2;
	VT2 = temp;
}
void List::SapXepTheoDonGia(bool (*Func)(int,int)) {
	for (int i = 0; i < this->PhanTu-1; i++) {
		for (int j = i + 1; j < this->PhanTu; j++) {
			if (Func((this->DanhSachVatTu + i)->LayDonGia(), (this->DanhSachVatTu + j)->LayDonGia())) {
				HoanVi(*(this->DanhSachVatTu+i),*(this->DanhSachVatTu+j));
			}
		}
	}
}
void List::SapXepTheoThanhTien(bool(*Func)(int, int)) {
	for (int i = 0; i < this->PhanTu - 1; i++) {
		for (int j = i + 1; j < this->PhanTu; j++) {
			if (Func((this->DanhSachVatTu + i)->LayThanhTien(), (this->DanhSachVatTu + j)->LayThanhTien())) {
				HoanVi(*(this->DanhSachVatTu + i), *(this->DanhSachVatTu + j));
			}
		}
	}
}
void List::SapXepTheoSoLuong(bool(*Func)(int, int)) {
	for (int i = 0; i < this->PhanTu - 1; i++) {
		for (int j = i + 1; j < this->PhanTu; j++) {
			if (Func((this->DanhSachVatTu + i)->LaySoLuong(),(this->DanhSachVatTu + j)->LaySoLuong())) {
				HoanVi(*(this->DanhSachVatTu + i), *(this->DanhSachVatTu + j));
			}
		}
	}
}

// Hàm hủy
List::~List() {
	cout << "Ham huy list duoc goi" << endl;
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
			newFile << (this->DanhSachVatTu + i)->LayNgayNhap() << " ";
			newFile << (this->DanhSachVatTu + i)->LayNhaSanXuat() << " ";
			newFile << (this->DanhSachVatTu + i)->LaySoLuong() << " ";
			newFile << (this->DanhSachVatTu + i)->LayDonGia() << " ";
			newFile << (this->DanhSachVatTu + i)->LayThanhTien() << " ";
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