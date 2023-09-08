#pragma once
#include "minecraft/item/ItemStack.h"

class ContainerItemStack {
public:
    //static ContainerItemStack EMPTY_ITEM;
private:
    ItemStack itemStackInstance;
    ItemInstance itemInstance;

public:
    ContainerItemStack() {};
    ContainerItemStack(const ItemStack& stack) : itemStackInstance(stack) {}
    ContainerItemStack(const ItemInstance&);
    ContainerItemStack operator-(const ContainerItemStack&);
    ContainerItemStack operator+(const ContainerItemStack&);
    operator bool(void) const;
    bool operator==(const ContainerItemStack&) const;
    bool operator==(const ItemStack&) const;
    bool operator==(const ItemInstance&) const;
    bool operator!=(const ContainerItemStack&) const;
    bool operator!=(const ItemStack&) const;
    bool operator!=(const ItemInstance&) const;
    const Item* getItem(void) const;
    int getId(void) const;
    short getAuxValue(void) const;
    void setAuxValue(short);
    int getIdAux(void) const;
    int getIdAuxEnchanted(void) const;
    short getDamageValue(void) const;
    void setDamageValue(short);
    bool isNull(void) const;
    void setNull(void);
    bool isEmpty(void) const;
    int getCount(void) const;
    void decreaseCount(int);
    void increaseCount(int);
    void forceSetCount(int);
    byte getStackSize(void) const;
    void setStackSize(byte);
    byte getMaxStackSize(void) const;
    bool matches(const ContainerItemStack&) const;
    bool matchesItem(const ContainerItemStack&) const;
    ItemDescriptor getDescriptor(void) const;
    bool hasUserData(void) const;
    const Unique<CompoundTag>& getUserData(void) const;
    Color getColor(void) const;
    ItemStack& getItemStack(void);
    const ItemStack& getItemStack(void) const;
    ItemInstance& getItemInstance(void);
    const ItemInstance& getItemInstance(void) const;
    ItemStack asItemStack(void) const;
    ItemInstance asItemInstance(void) const;

    ContainerItemStack(const ItemStack& itemStackInstance, const ItemInstance& itemInstance)
        : itemStackInstance(itemStackInstance), itemInstance(itemInstance)
    {
    }
};