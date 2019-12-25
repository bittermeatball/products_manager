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
	void Them(string, string, string, string, string, string, int, long long int, long long int);
	
	// Hàm xóa
	void XoaTheoMa(string);
	void XoaTheoTen(string);
	void XoaTheoLoai(string);
	void XoaTren100();
	
	// Hàm tìm kiếm
	void TimKiemTheoMa(string);
	void TimKiemTheoTen(string);
	void TimKiemTheoLoai(string);
	
	// Hàm sắp xếp ( sử dụng con trỏ hàm )
	void SapXepTheoSoLuong(bool(*)(long long int,long long int));
	void SapXepTheoDonGia(bool(*)(long long int, long long int));
	void SapXepTheoThanhTien(bool(*)(long long int, long long int));
	
	// Hàm ghi lại vào file
	void GhiVaoFile();
	
	// Hàm bạn hiển thị số phần tử
	friend int HienThiElement(List&);
	~List();
};

