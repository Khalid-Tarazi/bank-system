# bank-system

#  C++ Bank System

A comprehensive console-based banking system built in C++ that demonstrates Object-Oriented Programming principles, file handling, and data validation. This project is part of a learning journey to build a fully functional banking application with a user-friendly interface.

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Class Structure](#class-structure)
- [Project Architecture](#project-architecture)
- [Key Functionalities](#key-functionalities)
- [Technical Details](#technical-details)

## Overview

This C++ Bank Management System is a console-based application that provides a complete interface for managing bank clients. It allows users to perform CRUD operations (Create, Read, Update, Delete), handle transactions, and manage client accounts through a structured menu-driven interface.

The system utilizes file-based storage (`Clients.txt`) to persist client data and employs a modular class-based architecture for clean code organization.

## Features

### Core Banking Operations
- **Client Management**
  - Add new clients with unique account numbers
  - View complete client list
  - Find clients by account number
  - Update client information
  - Delete client accounts (soft delete)
  - Display client details in formatted cards

- **Transaction Operations**
  - Deposit funds to client accounts
  - Withdraw funds with balance validation
  - View total balances across all accounts
  - Show balance summary in numeric and word formats

### User Experience
- **Main Menu** with 8 options:
  1. Show Clients List
  2. Add New Client
  3. Delete Client
  4. Update Client Info
  5. Find Client
  6. Transactions Menu
  7. Manage Users (coming soon)
  8. Logout

- **Transaction Sub-menu** with 4 options:
  1. Deposit
  2. Withdraw
  3. Total Balances
  4. Main Menu

- **Input Validation**
  - Data type validation (numbers, strings, etc.)
  - Range checking for numeric inputs
  - Duplicate account number prevention
  - Client existence verification before operations

- **Formatted Display**
  - Clean table layouts for client lists
  - Organized client information cards
  - Proper alignment using stream manipulators
  - Menu headers with visual separators

## Class Structure

### Core Classes

| Class | Description | Key Features |
|-------|-------------|--------------|
| `clsBankClient` | Main client data model and file operations | CRUD operations, file I/O, static methods |
| `clsPerson` | Base class for person attributes | Name, email, phone, full name generation |
| `clsScreen` | Abstract screen template | Standardized header display |
| `clsMainScreen` | Main menu system | Menu rendering, option handling, navigation |
| `clsTransactionsScreen` | Transaction menu | Deposit, withdraw, balance operations |

### Screen Classes

| Class | Purpose | Key Methods |
|-------|---------|-------------|
| `clsAddNewClientScreen` | Add new client interface | `showAddNewClientScreen()` |
| `clsClientListScreen` | Display all clients | `showClientsList()` |
| `clsDeleteClientScreen` | Delete client interface | `showDeleteClientScreen()` |
| `clsFindClientScreen` | Search and display client | `showFindClientScreen()` |
| `clsUpdateClientScreen` | Update client information | `ShowUpdateClientScreen()` |

### Utility Classes

| Class | Purpose | Key Features |
|-------|---------|--------------|
| `clsInputValidate` | Input validation and sanitization | Number validation, date validation, string input |
| `clsDate` | Comprehensive date operations | Date manipulation, calculations, formatting |
| `clsString` | String manipulation utilities | Split, join, case conversion, trim, replace |
| `clsUtil` | General utility functions | Random generation, encryption, number to text |

## Project Architecture

┌─────────────────────────────────────────────────────────┐
│ Main Program │
│ (bank-system.cpp) │
└─────────────────────┬───────────────────────────────────┘
│
┌─────────────────────▼───────────────────────────────────┐
│ clsMainScreen │
│ (Main Menu Controller) │
└─────────────────────┬───────────────────────────────────┘
│
┌─────────────┼─────────────────┐
│ │ │
┌───────▼──────┐ ┌────▼──────┐ ┌───────▼──────┐
│ Client │ │Transaction│ │ Manage │
│ Screens │ │ Screens │ │ Users │
│ │ │ │ │ (Future) │
└───────┬──────┘ └─────┬─────┘ └──────────────┘
│ │
┌───────▼──────────────▼──────────────────────────────┐
│ clsBankClient │
│ (Business Logic Layer) │
└─────────────────────┬───────────────────────────────┘
│
┌─────────────────────▼───────────────────────────────┐
│ Data Storage │
│ Clients.txt │
└──────────────────────────────────────────────────────┘

## Technical Details
Language and Tools
Language: C++ (C++17 standard)

Compiler: Compatible with MSVC (Visual Studio), GCC, and Clang

File I/O: Standard <fstream> library

Data Storage: Plain text file (Clients.txt)

Data Format: Custom delimiter #//# for serialization


## Key Functionalities

### Client Data Management
// Add new client with unique account number
clsBankClient newClient = clsBankClient::getAddNewClientObject(accountNumber);
newClient.save();

// Find client by account number
clsBankClient client = clsBankClient::find(accountNumber);

// Delete client (soft delete)
client.Delete();

// Update client information
client.save(); // Auto-detects update mode
