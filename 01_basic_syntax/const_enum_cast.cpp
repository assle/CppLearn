#include <iostream>

enum class OrderStatus {
    Created,
    Paid,
    Shipped,
    Cancelled
};

int main() {
    const double discount_rate = 0.8;

    int original_price = 101;
    double discounted_price = original_price * discount_rate;

    int final_price = static_cast<int>(discounted_price);

    OrderStatus status = OrderStatus::Cancelled;

    std::cout << "original price: " << original_price << std::endl;
    std::cout << "discounted price: " << discounted_price << std::endl;
    std::cout << "final price: " << final_price << std::endl;

    if (status == OrderStatus::Cancelled) {
        std::cout << "order status: cancelled" << std::endl;
    }

    return 0;
}
