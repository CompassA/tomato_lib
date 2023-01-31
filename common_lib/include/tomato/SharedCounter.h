/*
 * @Author: Tomato
 * @Date: 2023-01-30 21:02:26
 * @LastEditTime: 2023-01-30 21:04:47
 */

namespace tomato {


class SharedCounter {
public:
    explicit SharedCounter(): cnt_(1) {}

    /**
     * @brief 计数+1
     * 
     */
    void add();

    /**
     * @brief 计数-1
     * 
     * @return -1后的计数值
     */
    long reduce();

    /**
     * @brief 获取当前计数值
     * 
     * @return 计数值
     */
    long get() const;

private:
    long cnt_;
};



}