# 🚀 ESP32 OTA Firmware Upload via Web Interface

Proyek ini memungkinkan Anda mengunggah firmware `.bin` ke ESP32 melalui browser — **tanpa kabel**, hanya dengan koneksi WiFi!

---

## 📁 Struktur Folder

```
esp32-ota-upload/
└── sketch/
    ├── sketch.ino         ← Kode utama ESP32 OTA
    └── data/
        └── index.html     ← Halaman web upload firmware
```

---

## 🛠️ Cara Menggunakan

1. **Upload SPIFFS**: Unggah file `index.html` ke SPIFFS (gunakan plugin "ESP32 Sketch Data Upload").
2. **Upload Sketch**: Flash `sketch.ino` ke ESP32 menggunakan Arduino IDE atau PlatformIO.
3. **Koneksi WiFi**: ESP32 akan membuat Access Point `ESP32-OTA` (password: `12345678`).
4. **Buka Browser**: Akses `http://192.168.4.1` dan upload file `.bin`.
5. **Otomatis Reboot**: Setelah berhasil, ESP32 akan restart dengan firmware baru.

---

## ✅ Cocok Untuk

- Mengupdate firmware via HP / browser
- Tanpa kabel USB
- Cocok untuk penggunaan lapangan

---

## 🤝 Kredit

Dibuat oleh: [@kajukopi](https://github.com/kajukopi)
