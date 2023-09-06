#pragma once

namespace MyFFL
{
    class Database
    {
        // Account
        void Login();
        void SetUser();
        void GetUser();
        // Customer
        void AddCustomer();
        void GetCustomer();
        // Inventory
        void AddInventory();
        void GetInventory();
        // Sales
        void AddSale();
        void GetSale();
        // Forms
        void AddForm1();
        void AddForm2();
        void AddForm3();
        void AddForm4();
        void Add4473();
        void AddAcquisition();
        void AddDisposition();

        void GetForm1();
        void GetForm2();
        void GetForm3();
        void GetForm4();
        void Get4473();
        void GetAcquisition();
        void GetDisposition();
        // Reports
        void G
        // Database
        void BackupDB();
        void RestoreDB();
        void ExportCSV();
        void ExportTXT();
    };
} // namespace MyFFL