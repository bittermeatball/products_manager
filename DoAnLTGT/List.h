#pragma once
#include "VatTu.h"
class List
{
private:
	VatTu* DanhSachVatTu;
	int PhanTu;
public:
	// Hàm dựng
	List();
	List(const List&);
	List(VatTu, int);
	
	// Hàm Hiển thị
	void HienThiList();
	
	// Hàm thêm
	void Them(string, string, string, string, string, string, int, int, int, int);
	
	// Hàm xóa
	void XoaTheoMa(string);
	void XoaTheoTen(string);
	void XoaTheoLoai(string);
	
	// Hàm tìm kiếm
	void TimKiemTheoMa(string);
	void TimKiemTheoTen(string);
	void TimKiemTheoLoai(string);
	
	// Hàm sắp xếp ( sử dụng con trỏ hàm )
	void SapXepTheoSoLuong(bool(*)(int, int));
	void SapXepTheoDonGia(bool(*)(int, int));
	void SapXepTheoThanhTien(bool(*)(int, int));
	
	// Hàm ghi lại vào file
	void GhiVaoFile();
	
	// Hàm bạn hiển thị số phần tử
	friend int HienThiElement(List&);
	~List();
};

