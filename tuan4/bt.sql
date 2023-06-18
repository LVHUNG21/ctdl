--1
CREATE PROCEDURE CapNhatDonHang
    @MaHoaDon INT,
    @NgayHoaDon DATE,
    @MaSanPham INT,
    @SoLuong INT
AS
BEGIN
    BEGIN TRY
        BEGIN TRANSACTION;
        UPDATE DonHang
        SET NgayHoaDon = @NgayHoaDon
        WHERE MaHoaDon = @MaHoaDon;
        UPDATE ChiTietDonHang
        SET GiaThanh = GiaThanh * 1.2
        WHERE MaHoaDon = @MaHoaDon AND MaSanPham = @MaSanPham;
        COMMIT TRANSACTION;
    END TRY
    BEGIN CATCH
        ROLLBACK TRANSACTION;
    END CATCH;
END
--2
CREATE TRIGGER KiemTraSanPhamNgungBan
ON ChiTietDonHang
AFTER INSERT, UPDATE
AS
BEGIN
    IF EXISTS (
        SELECT 1
        FROM inserted i
        INNER JOIN SanPham sp ON i.MaSanPham = sp.MaSanPham
        WHERE sp.NgungBan = 1
    )
    BEGIN
        RAISERROR ('Không thể thêm mới sảnphẩm.', 16, 1);
        ROLLBACK TRANSACTION;
    END;
END;
--3
CREATE TRIGGER KiemTraSanPhamNgungBanThayCho
ON ChiTietDonHang
INSTEAD OF INSERT, UPDATE
AS
BEGIN
    IF EXISTS (
        SELECT 1
        FROM inserted i
        INNER JOIN SanPham sp ON i.MaSanPham = sp.MaSanPham
        WHERE sp.NgungBan = 1
    )
    BEGIN
        RAISERROR ('Không thể thêmmới.', 16, 1);
        ROLLBACK TRANSACTION;
    END;
    ELSE
    BEGIN

    END;
END;
--4
CREATE TRIGGER NganNguaBanHangQuaNhieu
ON DonHang
AFTER INSERT
AS
BEGIN
    IF EXISTS (
        SELECT 1
        FROM inserted i
        INNER JOIN ChiTietDonHang ctdh ON i.MaHoaDon = ctdh.MaHoaDon
        INNER JOIN SanPham sp ON ctdh.MaSanPham = sp.MaSanPham
        WHERE ctdh.SoLuong > sp.SoLuongTrongKho / 2
    )
    BEGIN
        RAISERROR ('Không thể bánlượng còn trong kho.', 16, 1);
        ROLLBACK TRANSACTION;
    END;
END;
