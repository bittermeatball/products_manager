#include "VatTu.h"
// Hàm dựng
VatTu::VatTu()
	: MaVatTu("#"), TenVatTu("#"), LoaiVatTu("#"), DonViTinh("#"), NgayNhap("#"), NhaSanXuat("#"), 
	SoLuong(0), DonGia(0), ThanhTien(0)
{

}
VatTu::VatTu(string MaVatTu, string TenVatTu, string LoaiVatTu, string DonViTinh, string NgayNhap, string NhaSanXuat, int SoLuong, int DonGia, int ThanhTien)
	: MaVatTu(MaVatTu), TenVatTu(TenVatTu), LoaiVatTu(LoaiVatTu), DonViTinh(DonViTinh), NgayNhap(NgayNhap), NhaSanXuat(NhaSanXuat),
	SoLuong(SoLuong), DonGia(DonGia), ThanhTien(ThanhTien)
{

}
VatTu::VatTu(const VatTu& VT) {
	this->MaVatTu = VT.MaVatTu;
	this->TenVatTu = VT.TenVatTu;
	this->LoaiVatTu = VT.LoaiVatTu;
	this->DonViTinh = VT.DonViTinh;
	this->NgayNhap = VT.NgayNhap;
	this->NhaSanXuat = VT.NhaSanXuat;
	this->SoLuong = VT.SoLuong;
	this->DonGia = VT.DonGia;
	this->ThanhTien = VT.ThanhTien;
}

// Hàm getter
string VatTu::LayMaVatTu() const
{
	return this->MaVatTu;
}
string VatTu::LayTenVatTu() const
{
	return this->TenVatTu;
}
string VatTu::LayLoaiVatTu() const
{
	return this->LoaiVatTu;
}
string VatTu::LayDonViTinh() const
{
	return this->DonViTinh;
}
string VatTu::LayNgayNhap() const
{
	return this->NgayNhap;
}
string VatTu::LayNhaSanXuat() const
{
	return this->NhaSanXuat;
}
int VatTu::LaySoLuong() const
{
	return this->SoLuong;
}
int VatTu::LayDonGia() const
{
	return this->DonGia;
}
int VatTu::LayThanhTien() const
{
	return this->ThanhTien;
}

// Hàm hiển thị vật tư
void VatTu::HienThiVatTu()
{
	cout << setw(15) << MaVatTu << "|";
	cout << setw(20) << TenVatTu << "|";
	cout << setw(20) << LoaiVatTu << "|";
	cout << setw(25) << NhaSanXuat << "|";
	cout << setw(10) << SoLuong << "|";
	cout << setw(10) << DonGia << "|";
	cout << setw(10) << ThanhTien << "|";
	cout << setw(30) << NgayNhap << "|" << endl;
}

// Hàm hủy
VatTu::~VatTu() {
}

// Hàm đa năng hóa
const VatTu& VatTu::operator=(const VatTu& VT) {
	if (this != &VT) {
		this->MaVatTu = VT.MaVatTu;
		this->TenVatTu = VT.TenVatTu;
		this->LoaiVatTu = VT.LoaiVatTu;
		this->DonViTinh = VT.DonViTinh;
		this->NgayNhap = VT.NgayNhap;
		this->NhaSanXuat = VT.NhaSanXuat;
		this->SoLuong = VT.SoLuong;
		this->DonGia = VT.DonGia;
		this->ThanhTien = VT.ThanhTien;
	}
	return *this;
}