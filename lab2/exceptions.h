// exceptions.h
#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

class InvalidPasswordException : public std::runtime_error {
public:
    explicit InvalidPasswordException(const std::string& msg = "Invalid password")
            : std::runtime_error(msg) {}
};

class InsufficientFundsException : public std::runtime_error {
public:
    explicit InsufficientFundsException(const std::string& msg = "Insufficient funds")
            : std::runtime_error(msg) {}
};

class AccountNotFoundException : public std::runtime_error {
public:
    explicit AccountNotFoundException(const std::string& msg = "Account not found")
            : std::runtime_error(msg) {}
};

class TransactionFailedException : public std::runtime_error {
public:
    explicit TransactionFailedException(const std::string& msg = "Transaction failed")
            : std::runtime_error(msg) {}
};

class InvalidCardNumberException : public std::runtime_error {
public:
    explicit InvalidCardNumberException(const std::string& msg = "Invalid card number")
            : std::runtime_error(msg) {}
};

class PaymentCancelledException : public std::runtime_error {
public:
    explicit PaymentCancelledException(const std::string& msg = "Payment cancelled")
            : std::runtime_error(msg) {}
};

class ServiceAlreadyBookedException : public std::runtime_error {
public:
    explicit ServiceAlreadyBookedException(const std::string& msg = "Service already booked")
            : std::runtime_error(msg) {}
};

class PartNotInStockException : public std::runtime_error {
public:
    explicit PartNotInStockException(const std::string& msg = "Part not in stock")
            : std::runtime_error(msg) {}
};

class MechanicUnavailableException : public std::runtime_error {
public:
    explicit MechanicUnavailableException(const std::string& msg = "Mechanic unavailable")
            : std::runtime_error(msg) {}
};

class InvalidDateException : public std::runtime_error {
public:
    explicit InvalidDateException(const std::string& msg = "Invalid date")
            : std::runtime_error(msg) {}
};

class UserNotAuthenticatedException : public std::runtime_error {
public:
    explicit UserNotAuthenticatedException(const std::string& msg = "User not authenticated")
            : std::runtime_error(msg) {}
};

class DuplicateEntryException : public std::runtime_error {
public:
    explicit DuplicateEntryException(const std::string& msg = "Duplicate entry")
            : std::runtime_error(msg) {}
};

#endif // EXCEPTIONS_H