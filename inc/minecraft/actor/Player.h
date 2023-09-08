#pragma once

#include "Mob.h"
#include "Zenova.h"

class BlockActor;
class ChalkboardBlockActor;
class ChunkPos;
class ChunkSource;
class ComplexInventoryTransaction;
class Container;
class EventPacket;
class FrameUpdateContextBase;
class IContainerManager;
class IMinecraftEventing;
class InventoryTransaction;
class Item;
class MoveInputHandler;
class PlayerEventCoordinator;
class TextObjectRoot;
class Tick;

enum class BedSleepingResult : int;
enum class ClientPlayMode : int;
enum class CooldownType : int;
enum class GameType : int;
enum class MovementEventType : unsigned char;
enum class StructureFeatureType : signed char;

namespace Social { typedef unsigned int LocalUserId; }

class Player : public Mob {
public:
    virtual ~Player();
    virtual void initializeComponents(Actor::InitializationMethod, const VariantParameterList&);
    virtual void reloadHardcoded(Actor::InitializationMethod, const VariantParameterList&);
    virtual void prepareRegion(ChunkSource&);
    virtual void destroyRegion();
    virtual void suspendRegion();
    virtual void _fireWillChangeDimension();
    virtual void _fireDimensionChanged();
    virtual void changeDimensionWithCredits(DimensionType);
    virtual int tickWorld(const Tick&);
    virtual void frameUpdate(FrameUpdateContextBase&);
    virtual const std::vector<ChunkPos>& getTickingOffsets() const;
    virtual void normalTick();
    virtual void moveView();
    virtual void moveSpawnView(const Vec3&);
    virtual void setName(const std::string&);
    virtual void onSynchedDataUpdate(int);
    virtual void aiStep();
    virtual void move(const Vec3&);
    virtual void travel(float, float, float);
    virtual void checkMovementStats(const Vec3&);
    virtual StructureFeatureType getCurrentStructureFeature() const;
    virtual void jumpFromGround();
    virtual bool isAutoJumpEnabled() const;
    virtual void rideTick();
    virtual void die(const ActorDamageSource&);
    virtual void remove();
    virtual void respawn();
    virtual void dropEquipment(const ActorDamageSource&, int);
    virtual void dropEquipment();
    virtual bool drop(const ItemStack&, bool);
    virtual void resetRot();
    virtual void resetPos(bool);
    virtual bool isShootable();
    virtual bool isCreativeModeAllowed();
    virtual bool isInTrialMode();
    virtual void setSpeed(float);
    virtual bool hasResource(int);
    virtual void completeUsingItem();
    virtual int getItemUseDuration();
    virtual float getItemUseStartupProgress();
    virtual float getItemUseIntervalProgress();
    virtual bool isBlocking() const;
    virtual bool isDamageBlocked(const ActorDamageSource&) const;
    virtual void awardKillScore(Actor&, int);
    virtual void handleEntityEvent(ActorEvent, int);
    virtual std::vector<ItemStack const*> getAllHand() const;
    virtual std::vector<ItemStack const*> getAllEquipment() const;
    virtual bool add(ItemStack&);
    virtual CommandPermissionLevel getCommandPermissionLevel() const;
    virtual void setPermissions(CommandPermissionLevel);
    virtual void adjustDamageAmount(int&) const;
    virtual bool attack(Actor&);
    virtual const ItemStack& getCarriedItem() const;
    virtual void setCarriedItem(const ItemStack&);
    virtual void startCrafting(const BlockPos&, bool);
    virtual void startStonecutting(const BlockPos&);
    virtual void startDestroying();
    virtual void stopDestroying();
    virtual void openContainer(const BlockPos&);
    virtual void openContainer(const ActorUniqueID&);
    virtual void openFurnace(const BlockPos&);
    virtual void openBlastFurnace(const BlockPos&);
    virtual void openSmoker(const BlockPos&);
    virtual void openEnchanter(const BlockPos&);
    virtual void openAnvil(const BlockPos&);
    virtual void openGrindstone(const BlockPos&);
    virtual void openBrewingStand(const BlockPos&);
    virtual void openHopper(const BlockPos&);
    virtual void openHopper(const ActorUniqueID&);
    virtual void openDispenser(const BlockPos&, bool);
    virtual void openBeacon(const BlockPos&);
    virtual void openPortfolio();
    virtual void openBook(int, bool, int, BlockActor*);
    virtual void openCommandBlock(const BlockPos&);
    virtual void openCommandBlockMinecart(const ActorUniqueID&);
    virtual void openHorseInventory(const ActorUniqueID&);
    virtual void openTrading(const ActorUniqueID&, bool);
    virtual bool canOpenContainerScreen();
    virtual void openChalkboard(ChalkboardBlockActor&, bool);
    virtual void openNpcInteractScreen(Actor&);
    virtual void openInventory();
    virtual void openStructureEditor(const BlockPos&);
    virtual void openLabTable(const BlockPos&);
    virtual void openElementConstructor(const BlockPos&);
    virtual void openCompoundCreator(const BlockPos&);
    virtual void openMaterialReducer(const BlockPos&);
    virtual void openLoom(const BlockPos&);
    virtual void openStonecutter(const BlockPos&);
    virtual void openCartographyTable(const BlockPos&);
    virtual void displayChatMessage(const std::string&, const std::string&);
    virtual void displayClientMessage(const std::string&);
    virtual void displayLocalizableMessage(const std::string&, const std::vector<std::string>&);
    virtual void displayTextObjectMessage(const TextObjectRoot&, const std::string&, const std::string&);
    virtual void displayWhisperMessage(const std::string&, const std::string&, const std::string&, const std::string&);
    virtual float getCameraOffset() const;
    virtual float getRidingHeight();
    virtual ActorType getEntityTypeId() const;
    virtual bool isSleeping() const;
    virtual void setSleeping(bool);
    virtual BedSleepingResult startSleepInBed(const BlockPos&);
    virtual void stopSleepInBed(bool, bool);
    virtual bool canStartSleepInBed();
    virtual int getSleepTimer() const;
    virtual int getPreviousTickSleepTimer() const;
    virtual void sendInventory(bool);
    virtual void openSign(const BlockPos&);
    virtual void playEmote(const std::string&, bool);
    virtual bool isLocalPlayer() const;
    virtual bool isHostingPlayer() const;
    virtual bool useNewAi() const;
    virtual void useItem(ItemStack&, ItemUseMethod, bool);
    virtual bool isLoading() const;
    virtual bool isPlayerInitialized() const;
    virtual void stopLoading();
    virtual void registerTrackedBoss(ActorUniqueID);
    virtual void unRegisterTrackedBoss(ActorUniqueID);
    virtual bool isCreative() const;
    virtual bool isAdventure() const;
    virtual float getSpeed() const;
    virtual int getPortalCooldown() const;
    virtual int getPortalWaitTime() const;
    virtual void setPlayerGameType(GameType);
    virtual void _crit(Actor&);
    virtual bool isImmobile() const;
    virtual void sendMotionPacketIfNeeded();
    virtual IMinecraftEventing* getEventing() const;
    virtual Social::LocalUserId getUserId() const;
    virtual void sendEventPacket(EventPacket&) const;
    virtual void addExperience(int);
    virtual void addLevels(int);
    virtual void setArmor(ArmorSlot, const ItemStack&);
    virtual void setOffhandSlot(const ItemStack&);
    virtual std::unique_ptr<Packet> getAddPacket();
    virtual bool isWorldBuilder();
    virtual bool isInvulnerableTo(const ActorDamageSource&) const;
    virtual void setContainerData(IContainerManager&, int, int);
    virtual void slotChanged(IContainerManager&, int, const ItemStack&, const ItemStack&, bool);
    virtual void inventoryChanged(Container&, int, const ItemStack&, const ItemStack&);
    virtual void refreshContainer(IContainerManager&);
    virtual void deleteContainerManager();
    virtual const ItemStack& getEquippedTotem() const;
    virtual bool consumeTotem();
    virtual void setFieldOfViewModifier(float);
    virtual bool isPositionRelevant(DimensionType, const BlockPos&);
    virtual bool isEntityRelevant(const Actor&);
    virtual float getMapDecorationRotation() const;
    virtual void actuallyHurt(int, const ActorDamageSource*, bool);
    virtual void teleportTo(const Vec3&, bool, int, int);
    virtual void startSwimming();
    virtual void stopSwimming();
    virtual void startSpinAttack();
    virtual void stopSpinAttack();
    virtual bool isTeacher() const;
    virtual void onSuspension();
    virtual void onLinkedSlotsChanged();
    virtual bool canBePulledIntoVehicle() const;
    virtual void feed(int);
    virtual void startCooldown(const Item*);
    virtual int getItemCooldownLeft(CooldownType) const;
    virtual bool isItemInCooldown(CooldownType) const;
    virtual void sendInventoryTransaction(const InventoryTransaction&) const;
    virtual void sendComplexInventoryTransaction(std::unique_ptr<ComplexInventoryTransaction>) const;
    virtual void sendNetworkPacket(Packet&) const;
    virtual void updateGliding();
    virtual bool canExistWhenDisallowMob() const;
    virtual std::string getFormattedNameTag() const;
    virtual bool getAlwaysShowNameTag() const;
    virtual bool canAddRider(Actor&) const;
    virtual bool isJumping() const;
    virtual Vec3 getAttachPos(ActorLocation, float) const;
    virtual PlayerEventCoordinator& getPlayerEventCoordinator();
    virtual MoveInputHandler* getMoveInputHandler();
    virtual InputMode getInputMode() const;
    virtual ClientPlayMode getPlayMode() const;
    virtual void reportMovementTelemetry(const MovementEventType);
    virtual void updateAi();
    virtual bool _hurt(const ActorDamageSource&, int, bool, bool);
    virtual void readAdditionalSaveData(const CompoundTag&, DataLoadHelper&);
    virtual void addAdditionalSaveData(CompoundTag&);
    virtual void onMovePlayerPacketNormal(const Vec3&, const Vec2&, float);
    virtual void onBounceStarted(const BlockPos&, const Block&);
    virtual void _onSizeUpdated();
    virtual AnimationComponent& getAnimationComponent();
    virtual const HashedString& getActorRendererId() const;
    virtual std::unique_ptr<BodyControl> initBodyControl();//186
    virtual void filler0() {};
    virtual void filler1() {};
    virtual void filler2() {};
    virtual void filler3() {};
    virtual void filler4() {};
    virtual void filler5() {};
    virtual void filler6() {};
    virtual void filler7() {};
    virtual void filler8() {};
    virtual void filler9() {};
    virtual void filler10() {};
    virtual void filler11() {};
    virtual void filler12() {};
    virtual void filler13() {};
    virtual void filler14() {};
    virtual void filler15() {};
    virtual void filler16() {};
    virtual void filler17() {};
    virtual void filler18() {};
    virtual void filler19() {};
    virtual void filler20() {};
    virtual void filler21() {};
    virtual void filler22() {};
    virtual void filler23() {};
    virtual void filler24() {};
    virtual void filler25() {};
    virtual void filler26() {};
    virtual void filler27() {};
    virtual void filler28() {};
    virtual void filler29() {};
    virtual void filler30() {};
    virtual void filler31() {};
    virtual void filler32() {};
    virtual void filler33() {};
    virtual void filler34() {};
    virtual void filler35() {};
    virtual void filler36() {};
    virtual void filler37() {};
    virtual void filler38() {};
    virtual void filler39() {};
    virtual void filler40() {};
    virtual void filler41() {};
    virtual void filler42() {};
    virtual void filler43() {};
    virtual void filler44() {};
    virtual void filler45() {};
    virtual void filler46() {};
    virtual void filler47() {};
    virtual void filler48() {};
    virtual void filler49() {};
    virtual void filler50() {};
    virtual void filler51() {};
    virtual void filler52() {};
    virtual void filler53() {};
    virtual void filler54() {};
    virtual void filler55() {};
    virtual void filler56() {};
    virtual void filler57() {};
    virtual void filler58() {};
    virtual void filler59() {};
    virtual void filler60() {};
    virtual void filler61() {};
    virtual void filler62() {};
    virtual void filler63() {};
    virtual void filler64() {};
    virtual void filler65() {};
    virtual void filler66() {};
    virtual void filler67() {};
    virtual void filler68() {};
    virtual void filler69() {};
    virtual void filler70() {};
    virtual void filler71() {};
    virtual void filler72() {};
    virtual void filler73() {};
    virtual void filler74() {};
    virtual void filler75() {};
    virtual void filler76() {};
    virtual void filler77() {};
    virtual void filler78() {};
    virtual void filler79() {};
    virtual void filler80() {};
    virtual void filler81() {};
    virtual void filler82() {};
    virtual void filler83() {};
    virtual void filler84() {};
    virtual void filler85() {};
    virtual void filler86() {};
    virtual void filler87() {};
    virtual void filler88() {};
    virtual void filler89() {};
    virtual void filler90() {};
    virtual void filler91() {};
    virtual void filler92() {};
    virtual void filler93() {};
    virtual void filler94() {};
    virtual void filler95() {};
    virtual void filler96() {};
    virtual void filler97() {};
    virtual void filler98() {};
    virtual void filler99() {};
    virtual void filler100() {};
    virtual void filler101() {};
    virtual void filler102() {};
    virtual void filler103() {};
    virtual void filler104() {};
    virtual void filler105() {};
    virtual void filler106() {};
    virtual void filler107() {};
    virtual void filler108() {};
    virtual void filler109() {};
    virtual void filler110() {};
    virtual void filler111() {};
    virtual void filler112() {};
    virtual void filler113() {};
    virtual void filler114() {};
    virtual void filler115() {};
    virtual void filler116() {};
    virtual void filler117() {};
    virtual void filler118() {};
    virtual void filler119() {};
    virtual void filler120() {};
    virtual void filler121() {};
    virtual void filler122() {};
    virtual void filler123() {};
    virtual void filler124() {};
    virtual void filler125() {};
    virtual void filler126() {};
    virtual void filler127() {};
    virtual void filler128() {};
    virtual void filler129() {};
    virtual void filler130() {};
    virtual void filler131() {};
    virtual void filler132() {};
    virtual void filler133() {};
    virtual void filler134() {};
    virtual void filler135() {};
    virtual void filler136() {};
    virtual void filler137() {};
    virtual void filler138() {};
    virtual void filler139() {};
    virtual void filler140() {};
    virtual void filler141() {};
    virtual void filler142() {};
    virtual void filler143() {};
    virtual void filler144() {};
    virtual void filler145() {};
    virtual void filler146() {};
    virtual void filler147() {};
    virtual void filler148() {};
    virtual void filler149() {};
    virtual void filler150() {};
    virtual void filler151() {};
    virtual void filler152() {};
    virtual void filler153() {};
    virtual void filler154() {};
    virtual void filler155() {};
    virtual void filler156() {};
    virtual void filler157() {};
    virtual void filler158() {};
    virtual void filler159() {};
    virtual void filler160() {};
    virtual void filler161() {};
    virtual void filler162() {};
    virtual void filler163() {};
    virtual void filler164() {};
    virtual void filler165() {};
    virtual void filler166() {};
    virtual void filler167() {};
    virtual void filler168() {};
    virtual void filler169() {};
    virtual void filler170() {};
    virtual void filler171() {};
    virtual void filler172() {};
    virtual void filler173() {};
    virtual void filler174() {};
    virtual void filler175() {};
    virtual void filler176() {};
    virtual void filler177() {};
    virtual void filler178() {};
    virtual void filler179() {};
    virtual void filler180() {};
    virtual void filler181() {};
    virtual void filler182() {};
    virtual void filler183() {};
    virtual void filler184() {};
    virtual void filler185() {};
    virtual void filler186() {};
    virtual void filler187() {};
    virtual void filler188() {};
    virtual void filler189() {};
    virtual void filler190() {};
    virtual void filler191() {};
    virtual void filler192() {};
    virtual void filler193() {};
    virtual void filler194() {};
    virtual void filler195() {};
    virtual void filler196() {};
    virtual void filler197() {};
    virtual void filler198() {};
    virtual void filler199() {};
    virtual void filler200() {};
    virtual void filler201() {};
    virtual void filler202() {};
    virtual void filler203() {};
    virtual void filler204() {};
    virtual void filler205() {};
    virtual void filler206() {};
    virtual void filler207() {};
    virtual void filler208() {};
    virtual void filler209() {};
    virtual void filler210() {};
    virtual void filler211() {};
    virtual void filler212() {};
    virtual void filler213() {};
    virtual void filler214() {};
    virtual void filler215() {};
    virtual void filler216() {};
    virtual void filler217() {};
    virtual void filler218() {};
    virtual void filler219() {};
    virtual void filler220() {};
    virtual void filler221() {};
    virtual void filler222() {};
    virtual void filler223() {};
    virtual void filler224() {};
    virtual void filler225() {};
    virtual void filler226() {};
    virtual void filler227() {};
    virtual void filler228() {};
    virtual void filler229() {};
    virtual void filler230() {};
    virtual void filler231() {};
    virtual void filler232() {};
    virtual void filler233() {};
    virtual void filler234() {};
    virtual void filler235() {};
    virtual void filler236() {};
    virtual void filler237() {};
    virtual void filler238() {};
    virtual void filler239() {};
    virtual void filler240() {};
    virtual void filler241() {};
    virtual void filler242() {};
    virtual void filler243() {};
    virtual void filler244() {};
    virtual void filler245() {};
    virtual void filler246() {};
    virtual void filler247() {};
    virtual void filler248() {};
    virtual void filler249() {};
    virtual void filler250() {};
    virtual void filler251() {};
    virtual void filler252() {};
    virtual void filler253() {};
    virtual void filler254() {};
    virtual void filler255() {};
    virtual void filler256() {};
    virtual void filler257() {};
    virtual void filler258() {};
    virtual void filler259() {};
    const ItemStack& getSelectedItem() const;
    void causeFoodExhaustion(float);
public:
    void setContainerManager(std::shared_ptr<class IContainerManager>);
};