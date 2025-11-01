Автомастерская

## Общая статистика

| Категория         | Количество |
|-------------------|----------|
| Классы            | 50       |
| Поля              | 193      |
| Методы (поведения) | 175      |
| Ассоциации        | 67       |
| Исключения        | 12       |

---

##  Классы

### 🔹 `core/` — Компоненты автомобиля (11 классов)

#### 1. `Battery`
- **Поля (4)**: `id`, `voltage`, `capacityAh`, `isCharged`
- **Методы (5)**: `charge()`, `discharge()`, `getIsCharged()`, `getVoltage()`, `getCapacityAh()`
- **Ассоциации**: Нет

#### 2. `BrakeSystem`
- **Поля (3)**: `type`, `padWearPercentage`, `isFunctional`
- **Методы (4)**: `inspect()`, `replacePads()`, `getPadWear()`, `getIsFunctional()`
- **Ассоциации**: Нет

#### 3. `Car`
- **Поля (11)**: `vin`, `model`, `year`, `engine`, `transmission`, `battery`, `brakes`, `suspension`, `tires[4]`, `steering`, `headlights[2]`, `radiator`, `exhaust`
- **Методы (8)**: `startEngine()`, `stopEngine()`, `drive()`, `brake()`, `turnLeft()`, `turnRight()`, `getVin()`, `getModel()`
- **Ассоциации**: → `Engine`, `Transmission`, `Battery`, `BrakeSystem`, `Suspension`, `Tire`, `SteeringWheel`, `Headlight`, `Radiator`, `ExhaustSystem`

#### 4. `Engine`
- **Поля (3)**: `type`, `horsepower`, `isRunning`
- **Методы (4)**: `start()`, `stop()`, `getIsRunning()`, `getHorsepower()`
- **Ассоциации**: Нет

#### 5. `ExhaustSystem`
- **Поля (3)**: `id`, `material`, `noiseLevelDb`
- **Методы (4)**: `inspect()`, `replace()`, `getNoiseLevel()`, `getMaterial()`
- **Ассоциации**: Нет

#### 6. `Headlight`
- **Поля (3)**: `id`, `type`, `isOn`
- **Методы (4)**: `turnOn()`, `turnOff()`, `getIsOn()`, `getType()`
- **Ассоциации**: Нет

#### 7. `Radiator`
- **Поля (3)**: `id`, `coolantLevel`, `isLeaking`
- **Методы (4)**: `checkCoolant()`, `refillCoolant()`, `getCoolantLevel()`, `getIsLeaking()`
- **Ассоциации**: Нет

#### 8. `SteeringWheel`
- **Поля (2)**: `type`, `angleDegrees`
- **Методы (4)**: `turnLeft()`, `turnRight()`, `getAngle()`, `getType()`
- **Ассоциации**: Нет

#### 9. `Suspension`
- **Поля (2)**: `type`, `shockAbsorberWear`
- **Методы (4)**: `inspect()`, `replaceShockAbsorbers()`, `getShockAbsorberWear()`, `getType()`
- **Ассоциации**: Нет

#### 10. `Tire`
- **Поля (4)**: `id`, `type`, `treadDepth`, `rimSize`
- **Методы (4)**: `inspect()`, `rotate()`, `getTreadDepth()`, `getType()`
- **Ассоциации**: Нет

#### 11. `Transmission`
- **Поля (3)**: `type`, `gear`, `isEngaged`
- **Методы (4)**: `shiftUp()`, `shiftDown()`, `getGear()`, `getType()`
- **Ассоциации**: Нет

---

### `employees/` — Персонал (1 класс)

#### 12. `Mechanic`
- **Поля (4)**: `name`, `specialty`, `yearsExperience`, `isAvailable`
- **Методы (6)**: `assignToJob()`, `completeJob()`, `takeBreak()`, `getName()`, `getSpecialty()`, `getIsAvailable()`
- **Ассоциации**: → `ServiceOrder` (через `assignToJob`)

---

###  `inventory/` — Инвентарь (5 классов)

#### 13. `DiagnosticTool`
- **Поля (3)**: `id`, `brand`, `isConnected`
- **Методы (4)**: `connectToCar()`, `runDiagnostics()`, `disconnect()`, `getIsConnected()`, `getBrand()`
- **Ассоциации**: → `Car` (параметр метода), → `DiagnosticReport`

#### 14. `Part`
- **Поля (4)**: `id`, `name`, `price`, `quantityInStock`
- **Методы (5)**: `setQuantity()`, `getQuantity()`, `getPrice()`, `getName()`, `use()`
- **Ассоциации**: → `Warehouse`, → `Shipment`, → `InventoryManager`, → `OilChange`, → `PartsCatalog`

#### 15. `Supplier`
- **Поля (3)**: `name`, `contactInfo`, `address`
- **Методы (4)**: `getName()`, `getContactInfo()`, `getAddress()`, `placeOrder()`
- **Ассоциации**: → `Shipment`

#### 16. `Tool`
- **Поля (4)**: `id`, `name`, `type`, `isAvailable`
- **Методы (4)**: `borrow()`, `returnTool()`, `getIsAvailable()`, `getName()`
- **Ассоциации**: → `Warehouse`, → `ToolInventory`

#### 17. `Warehouse`
- **Поля (2)**: `location`, `parts`, `tools`
- **Методы (6)**: `addPart()`, `addTool()`, `findPartById()`, `findToolById()`, `listInventory()`
- **Ассоциации**: → `Part`, → `Tool`, → `InventoryManager`

---

###  `operations/` — Операции обслуживания (6 классов)

#### 18. `DiagnosticReport`
- **Поля (4)**: `reportId`, `car`, `tool`, `findings`, `conclusion`
- **Методы (5)**: `addFinding()`, `generateConclusion()`, `printReport()`, `getReportId()`
- **Ассоциации**: → `Car`, → `DiagnosticTool`, → `DiagnosticResult`

#### 19. `OilChange`
- **Поля (5)**: `car`, `oilFilter`, `engineOil`, `oilQuantityLiters`, `description`
- **Методы (4)**: `perform()`, `schedule()`, `getOilQuantity()`
- **Ассоциации**: → `Car`, → `Part`, → `Service`

#### 20. `PaintJob`
- **Поля (5)**: `car`, `color`, `paintAreaSqM`, `isComplete`, `description`
- **Методы (4)**: `perform()`, `schedule()`, `getColor()`, `getIsComplete()`
- **Ассоциации**: → `Car`, → `Service`

#### 21. `Service` (абстрактный)
- **Поля (2)**: `description`, `isCompleted`
- **Методы (4)**: `perform()`, `schedule()`, `getIsCompleted()`, `getDescription()`
- **Ассоциации**: ← `OilChange`, `PaintJob`, `WheelAlignment`, `ServiceOrder`

#### 22. `ServiceOrder`
- **Поля (5)**: `orderId`, `orderDate`, `services`, `assignedMechanic`, `status`
- **Методы (6)**: `addService()`, `assignMechanic()`, `complete()`, `printOrder()`, `getOrderId()`, `getServices()`
- **Ассоциации**: → `Service`, → `Mechanic`, → `Invoice`, → `Workshop`, → `JobAssignment`

#### 23. `WheelAlignment`
- **Поля (5)**: `car`, `toeIn`, `camber`, `caster`, `isAligned`
- **Методы (4)**: `perform()`, `schedule()`, `getIsAligned()`
- **Ассоциации**: → `Car`, → `Service`

---

###  `utilities/` — Утилиты (2 класса)

#### 24. `ContactInfo`
- **Поля (3)**: `phone`, `email`, `address`
- **Методы (5)**: `getPhone()`, `getEmail()`, `getAddress()`, `updatePhone()`, `updateEmail()`
- **Ассоциации**: → `Workshop`, → `Supplier`

#### 25. `Date`
- **Поля (3)**: `day`, `month`, `year`
- **Методы (7)**: конструкторы, `getDay()`, `getMonth()`, `getYear()`, `toString()`, `operator<`, `operator==`
- **Ассоциации**: → `Invoice`, → `ServiceOrder`, → `Shipment`, → `MaintenancePlan`

---

###  `finance/` — Финансы (5 классов)

#### 26. `BankAccount`
- **Поля (4)**: `accountNumber`, `balance`, `ownerName`, `currency`
- **Методы (6)**: `deposit()`, `withdraw()`, `transferTo()`, `getBalance()`, `getAccountNumber()`, `getOwnerName()`
- **Ассоциации**: → `CreditCard`, → `PaymentProcessor`, → `FuelingStation`, → `Invoice`

#### 27. `CreditCard`
- **Поля (5)**: `cardNumber`, `holderName`, `linkedAccount`, `creditLimit`, `currentDebt`
- **Методы (5)**: `validatePin()`, `makePayment()`, `getAvailableCredit()`, `getCardNumber()`
- **Ассоциации**: → `BankAccount`, → `PaymentProcessor`

#### 28. `PaymentProcessor`
- **Поля (0)**
- **Методы (2)**: `processPayment()`, `refund()`
- **Ассоциации**: → `CreditCard`, → `BankAccount`

#### 29. `Invoice`
- **Поля (6)**: `invoiceId`, `issueDate`, `dueDate`, `totalAmount`, `paid`, `relatedOrder`
- **Методы (5)**: `markAsPaid()`, `isOverdue()`, `getRemainingBalance()`, `getInvoiceId()`, `getTotalAmount()`
- **Ассоциации**: → `ServiceOrder`, → `FinancialReport`, → `PaymentReceipt`

#### 30. `PaymentReceipt`
- **Поля (5)**: `receiptId`, `paymentDate`, `amountPaid`, `relatedInvoice`, `paymentMethod`
- **Методы (3)**: `printReceipt()`, `getReceiptId()`, `getAmountPaid()`
- **Ассоциации**: → `Invoice`

---

###  `workshop/` — Мастерская (9 классов)

#### 31. `Workshop`
- **Поля (6)**: `name`, `address`, `mechanics`, `activeOrders`, `inventoryManager`, `auditLog`
- **Методы (7)**: `addMechanic()`, `createServiceOrder()`, `assignOrderToMechanic()`, `completeOrder()`, `printStatus()`, `getName()`
- **Ассоциации**: → `Mechanic`, → `ServiceOrder`, → `InventoryManager`, → `AuditLog`

#### 32. `ServiceSchedule`
- **Поля (3)**: `scheduledOrders`, `startDate`, `endDate`
- **Методы (5)**: `addOrder()`, `removeOrder()`, `printSchedule()`, `getOrdersForDate()`
- **Ассоциации**: → `ServiceOrder`

#### 33. `QualityControl`
- **Поля (5)**: `inspectorName`, `inspectionRating`, `inspectedOrder`, `comments`
- **Методы (5)**: `inspect()`, `setRating()`, `addComments()`, `getRating()`, `getComments()`, `getInspectorName()`
- **Ассоциации**: → `ServiceOrder`

#### 34. `RepairLog`
- **Поля (2)**: `repairHistory`, `workshopName`
- **Методы (4)**: `addRepair()`, `printLog()`, `getRepairsByDate()`, `getWorkshopName()`
- **Ассоциации**: → `ServiceOrder`

#### 35. `PartsCatalog`
- **Поля (1)**: `parts`
- **Методы (5)**: `addPart()`, `findPartByName()`, `getAllParts()`, `printCatalog()`
- **Ассоциации**: → `Part`

#### 36. `ToolInventory`
- **Поля (1)**: `tools`
- **Методы (5)**: `addTool()`, `findToolByName()`, `getAllTools()`, `printInventory()`
- **Ассоциации**: → `Tool`

#### 37. `JobAssignment`
- **Поля (4)**: `mechanic`, `order`, `assignmentDate`, `status`
- **Методы (5)**: `startWork()`, `completeWork()`, `cancel()`, `getStatus()`, `getAssignmentDetails()`
- **Ассоциации**: → `Mechanic`, → `ServiceOrder`

#### 38. `DiagnosticResult`
- **Поля (4)**: `report`, `recommendedActions`, `isCritical`
- **Методы (5)**: `addRecommendedAction()`, `setCritical()`, `printResult()`, `getSummary()`
- **Ассоциации**: → `DiagnosticReport`

#### 39. `MaintenancePlan`
- **Поля (4)**: `car`, `nextServiceDate`, `scheduledServices`, `estimatedCost`
- **Методы (5)**: `addService()`, `updateNextServiceDate()`, `printPlan()`, `getCarVin()`, `getNextServiceDate()`
- **Ассоциации**: → `Car`, → `Date`

---

###  `logistics/` — Логистика (3 класса)

#### 40. `Shipment`
- **Поля (5)**: `supplier`, `parts`, `shipmentDate`, `trackingNumber`, `delivered`
- **Методы (5)**: `addPart()`, `deliver()`, `markAsDelivered()`, `getTrackingNumber()`, `getIsDelivered()`
- **Ассоциации**: → `Supplier`, → `Part`, → `DeliveryNote`

#### 41. `InventoryManager`
- **Поля (2)**: `warehouse`, `stockLevels`
- **Методы (6)**: `updateStock()`, `getStockLevel()`, `isAvailable()`, `reorderParts()`, `printStockReport()`
- **Ассоциации**: → `Warehouse`, → `Part`, → `Tool`

#### 42. `DeliveryNote`
- **Поля (3)**: `shipment`, `deliveryDate`, `receiverSignature`
- **Методы (4)**: `sign()`, `isSigned()`, `getDeliveryDetails()`
- **Ассоциации**: → `Shipment`

---

### 📊 `reports/` — Отчетность (3 класса)

#### 43. `FinancialReport`
- **Поля (3)**: `invoices`, `totalRevenue`, `totalExpenses`
- **Методы (5)**: `calculateTotals()`, `getNetProfit()`, `exportToCSV()`, `printReport()`
- **Ассоциации**: → `Invoice`

#### 44. `ServiceStatistics`
- **Поля (3)**: `orders`, `totalServices`, `averageCost`
- **Методы (4)**: `computeStats()`, `getTotalServices()`, `getAverageCost()`, `printStats()`
- **Ассоциации**: → `ServiceOrder`

#### 45. `CustomerFeedback`
- **Поля (4)**: `customerName`, `rating`, `comment`, `resolved`
- **Методы (4)**: `resolve()`, `getRating()`, `getComment()`, `getCustomerName()`
- **Ассоциации**: → `Workshop` (косвенно)

---

###  `security/` — Безопасность и аудит (2 класса)

#### 46. `AuditLog`
- **Поля (1)**: `entries`
- **Методы (5)**: `logAction()`, `exportLogs()`, `getEntriesByActor()`, `printLogs()`
- **Ассоциации**: → `Workshop`, → `SecurityManager`

#### 47. `SecurityManager`
- **Поля (2)**: `audit`, `blockedUsers`
- **Методы (5)**: `blockUser()`, `unblockUser()`, `logSecurityEvent()`, `printBlockedUsers()`
- **Ассоциации**: → `AuditLog`

---

###  `services/` — Дополнительные услуги (3 класса)

#### 48. `CarRental`
- **Поля (6)**: `rentedCar`, `renterName`, `startDate`, `endDate`, `dailyRate`, `isReturned`
- **Методы (4)**: `calculateTotalCost()`, `returnCar()`, `getIsReturned()`, `getRenterName()`
- **Ассоциации**: → `Car`, → `Date`

#### 49. `TowingService`
- **Поля (5)**: `towedCar`, `requesterName`, `destination`, `cost`, `isCompleted`
- **Методы (4)**: `dispatch()`, `complete()`, `getCost()`, `getDestination()`
- **Ассоциации**: → `Car`

#### 50. `FuelingStation`
- **Поля (4)**: `car`, `paymentAccount`, `fuelPricePerLiter`, `litersFilled`
- **Методы (4)**: `refuel()`, `getTotalCost()`, `getFuelingDetails()`
- **Ассоциации**: → `Car`, → `BankAccount`

---

##  Исключения (12 шт.)


| Имя исключения                 | Описание                                      |
|-------------------------------|-----------------------------------------------|
| `InvalidPasswordException`    | Неверный пароль/ПИН                           |
| `InsufficientFundsException`  | Недостаточно средств на счете                 |
| `AccountNotFoundException`    | Аккаунт или часть не найдены                  |
| `TransactionFailedException`  | Ошибка при переводе денег                     |
| `InvalidCardNumberException`  | Неверный номер карты                          |
| `PaymentCancelledException`   | Оплата отменена                               |
| `ServiceAlreadyBookedException` | Услуга уже забронирована                   |
| `PartNotInStockException`     | Запчасть отсутствует на складе                |
| `MechanicUnavailableException`| Механик занят или недоступен                  |
| `InvalidDateException`        | Некорректная дата                             |
| `UserNotAuthenticatedException` | Пользователь не авторизован (не используется) |
| `DuplicateEntryException`     | Дублирующая запись                            |

---

