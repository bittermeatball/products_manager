#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
#include "Helpers.h"
using namespace std;
class VatTu
{
private:
	string MaVatTu;
	string TenVatTu;
	string LoaiVatTu;
	string DonViTinh;
	string NgayNhap;
	string NhaSanXuat;
	int SoLuong;
	long long int DonGia;
	long long int ThanhTien;
public:
	// Hàm dựng
	VatTu();
	VatTu(string, string, string, string, string, string, int, long long int, long long int);
	VatTu(const VatTu&);
	// Các hàm getter
	string LayMaVatTu() const;
	string LayTenVatTu() const;
	string LayLoaiVatTu() const;
	string LayDonViTinh() const;
	string LayNgayNhap() const;
	string LayNhaSanXuat() const;
	int LaySoLuong() const;
	long long int LayDonGia() const;
	long long int LayThanhTien() const;
	
	// Hàm hiển thị
	void HienThiVatTu();
	
	// Đa năng hóa phép gán ( Để sử dụng hoán vị 2 đối tượng )
	const VatTu& operator=(const VatTu&);
	~VatTu();
};

