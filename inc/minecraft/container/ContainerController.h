#pragma once
#include <memory>
#include "ContainerModel.h"

class Recipes;
enum class ItemAddType : int { All, Partial, None };
enum class ItemSetType : int { Place, Swap, Add, None };
enum class ItemTakeType : int { All, Half, One };
enum class ItemPlaceType : int { All, One };

struct ItemTransferAmount {
    enum class ItemTransferAmountTag : int {
        RequestAmount,
        TakeType,
        PlaceType
    };
    const ItemTransferAmountTag mTag;
    union {
        int requestAmount;
        ItemTakeType takeType;
        ItemPlaceType placeType;
    } mData;
    const bool mFromMax;

public:
    ItemTransferAmount(int requestAmount) : mTag(ItemTransferAmountTag::RequestAmount), mFromMax(false) { mData.requestAmount = requestAmount; }
    ItemTransferAmount(ItemTakeType takeType) : mTag(ItemTransferAmountTag::TakeType), mFromMax(false) { mData.takeType = takeType; }
    ItemTransferAmount(ItemPlaceType placeType) : mTag(ItemTransferAmountTag::PlaceType), mFromMax(false) { mData.placeType = placeType; }
    ItemTransferAmount(const ItemTransferAmount& tag, bool fromMax) : mTag(tag.mTag), mData(tag.mData), mFromMax(fromMax) {}
    ItemTransferAmount fromMaxStackSize(void) const { return ItemTransferAmount(64); }
};

class ContainerController {
protected:
    std::weak_ptr<ContainerModel> mContainerModel;
private:
    bool mDrop;

public:
    ContainerController(std::weak_ptr<ContainerModel> model, bool drop) : 
        mContainerModel(model), mDrop(drop) 
    {}
    virtual ~ContainerController();
    virtual bool isItemAllowed(const ItemInstance&) const;
    virtual bool isItemAllowedAtSlot(const ContainerItemStack&, int) const;
    virtual bool isItemFiltered(const Recipes&, const ContainerItemStack&) const;
    virtual int getBackgroundStyle(int) const;
    virtual ItemSetType _canSet(int, const ContainerItemStack&, ItemTransferAmount) const;
    virtual int _getAvailableSetCount(int, const ContainerItemStack&) const;
    virtual int _getAvailableAddCount(int) const;
    virtual bool _canRemove(int, int) const;
    virtual void _onItemChanged(int);

    ContainerModel& getContainerModel() const {
        return *mContainerModel.lock();
    }
};