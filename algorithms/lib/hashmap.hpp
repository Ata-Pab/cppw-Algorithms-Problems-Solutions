#pragma once
#include <vector>
#include <list>
#include <utility>
#include <functional>
#include <stdexcept>

namespace DataStructures
{
    template <typename Key, typename Value>
    struct HashNode
    {
        Key key;
        Value value;

        HashNode(const Key &k, const Value &v)
            : key(k), value(v) {}
    };

    template <typename Key, typename Value>
    class HashMap
    {
    private:
        std::vector<std::list<HashNode<Key, Value>>> buckets;
        size_t currentSize;
        size_t bucketCount;

        size_t hashKey(const Key &key) const
        {
            return std::hash<Key>{}(key) % bucketCount;
        }

    public:
        explicit HashMap(size_t bucketsSize = 16)
            : bucketCount(bucketsSize), currentSize(0)
        {
            buckets.resize(bucketCount);
        }

        size_t size() const
        {
            return currentSize;
        }

        bool empty() const
        {
            return currentSize == 0;
        }

        void put(const Key &key, const Value &value)
        {
            size_t index = hashKey(key);

            for (auto &node : buckets[index])
            {
                if (node.key == key)
                {
                    node.value = value;
                    return;
                }
            }

            buckets[index].emplace_back(key, value);
            currentSize++;
        }

        Value &get(const Key &key)
        {
            size_t index = hashKey(key);

            for (auto &node : buckets[index])
            {
                if (node.key == key)
                {
                    return node.value;
                }
            }

            throw std::out_of_range("Key not found");
        }

        bool contains(const Key &key) const
        {
            size_t index = hashKey(key);

            for (const auto &node : buckets[index])
            {
                if (node.key == key)
                    return true;
            }

            return false;
        }

        bool remove(const Key &key)
        {
            size_t index = hashKey(key);
            auto &bucket = buckets[index];

            for (auto it = bucket.begin(); it != bucket.end(); ++it)
            {
                if (it->key == key)
                {
                    bucket.erase(it);
                    currentSize--;
                    return true;
                }
            }

            return false;
        }

        void clear()
        {
            for (auto &bucket : buckets)
            {
                bucket.clear();
            }

            currentSize = 0;
        }
    };

} // namespace DataStructures