# Bank System

A comprehensive, console-based banking system built in C++ that demonstrates Object-Oriented Programming principles, advanced file handling, and robust data validation. This project showcases a fully functional banking application with a user-friendly, menu-driven interface.

[![C++](https://img.shields.io/badge/C++-17-blue.svg)](https://isocpp.org/)
[![Platform](https://img.shields.io/badge/platform-Windows%20%7C%20Linux-lightgrey.svg)]()

## Table of Contents

- [Overview](#overview)
- [Key Features](#key-features)
    - [Client Management](#client-management)
    - [Transaction Operations](#transaction-operations)
    - [Currency Exchange](#currency-exchange)
    - [User & Login Management](#user--login-management)
- [Class Architecture](#class-architecture)
    - [Core Domain Classes](#core-domain-classes)
    - [Screen (UI) Classes](#screen-ui-classes)
    - [Utility Classes](#utility-classes)
- [Technical Details](#technical-details)
- [Getting Started](#getting-started)
    - [Prerequisites](#prerequisites)
    - [Installation & Setup](#installation--setup)
    - [Running the Application](#running-the-application)
    - [Default Login](#default-login)
- [Project Structure](#project-structure)
- [Screenshots](#screenshots)
- [Future Enhancements](#future-enhancements)
- [Contributing](#contributing)
- [License](#license)

## Overview

This C++ Bank Management System is a console-based application providing a complete interface for managing bank clients, users, and financial transactions. It allows users to perform CRUD operations, handle deposits/withdrawals, manage currencies, and track user logins, all through a structured menu system.

The system utilizes file-based storage (`Clients.txt`, `Users.txt`, `Currencies.txt`, `TransferLog.txt`, `LoginRegister.txt`) to persist data and employs a modular, class-based architecture for clean code organization and maintainability.

## Key Features

### Client Management
- **Add New Clients** with unique, auto-generated account numbers.
- **View Complete Client List** in a formatted table.
- **Find Clients** by account number.
- **Update Client Information** (name, phone, email, etc.).
- **Delete Client Accounts** (soft delete).

### Transaction Operations
- **Deposit** funds to client accounts.
- **Withdraw** funds with real-time balance validation.
- **Transfer** funds between clients with logging.
- **View Total Balances** across all accounts, displayed in numeric and word formats.

### Currency Exchange
- **View Currencies List** with real-time rates.
- **Find Currency** by code or name.
- **Update Currency Rates** (admin functionality).
- **Currency Calculator** to convert between different currencies.

### User & Login Management
- **Manage System Users** (Admin & Normal User roles).
- **Add, Find, Update, and Delete Users**.
- **Track Login History** with timestamps in `LoginRegister.txt`.
- **Secure Password Encryption** using a custom utility.

## Class Architecture

The project is structured using a clean, OOP-centric design. Here are the main class categories:

### Core Domain Classes
| Class | Description | Key Features |
| :--- | :--- | :--- |
| **`clsPerson`** | Base class for all persons. | Handles common attributes: Name, Email, Phone. |
| **`clsBankClient`** | Main client data model. | CRUD operations, static `find()`, `save()`, `Delete()`. |
| **`clsUser`** | System user data model. | Manages user credentials and permissions. |
| **`clsCurrency`** | Currency model. | Handles currency codes, names, and exchange rates. |

### Screen (UI) Classes
These classes handle all user interaction and inherit from the `clsScreen` base class.
- **`clsMainScreen`**: The main menu system.
- **`clsTransactionsScreen`**: The transaction sub-menu.
- **`clsCurrencyExchangeMainScreen`**: The currency exchange menu.
- **`clsManageUsersScreen`**: Menu for user management.
- **`cls*Screen`**: Dedicated screens for each operation (e.g., `clsAddNewClientScreen`, `clsDepositScreen`, `clsFindCurrencyScreen`).

### Utility Classes
| Class | Purpose | Key Features |
| :--- | :--- | :--- |
| **`clsInputValidate`** | Input sanitization. | Number/string validation, range checking. |
| **`clsDate`** | Comprehensive date operations. | Manipulation, calculations, formatting. |
| **`clsString`** | String manipulation utilities. | `split()`, `join()`, `trim()`, `replace()`. |
| **`clsUtil`** | General utility functions. | Random generation, number-to-text conversion, encryption. |

## Technical Details

- **Language & Standard**: C++ (C++17)
- **Compilers**: Compatible with MSVC (Visual Studio), GCC, and Clang.
- **File I/O**: Standard library `<fstream>`.
- **Data Storage**: Plain text files (`.txt`).
- **Serialization**: Custom delimiter `#//#` for structured data.
- **Build System**: Visual Studio Solution (`.sln`) included.

##  Getting Started

### Prerequisites
- A C++ compiler supporting the C++17 standard (e.g., MSVC, GCC 7+, Clang 5+).
- (Optional) Visual Studio for the included solution file.

### Installation & Setup
**Clone the repository:**
    ```bash
    git clone https://github.com/Khalid-Tarazi/bank-system.git

**cd bank-system**
