// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/ABCharacterBase.h"
#include "Components/Capsulecomponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "ABCharacterControlData.h"

// Sets default values
AABCharacterBase::AABCharacterBase()
{
 	//Pawn의 회전을 위한 세팅
    bUseControllerRotationRoll = false;
    bUseControllerRotationPitch = false;
    bUseControllerRotationYaw = false;
    
    //Capsule
    GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
    GetCapsuleComponent()->SetCollisionProfileName(TEXT("Pawn"));

    //Movement
    GetCharacterMovement()->bOrientRotationToMovement = true;
    GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);
    GetCharacterMovement()->JumpZVelocity = 700.0f;
    GetCharacterMovement()->AirControl = 0.35f;
    GetCharacterMovement()->MaxWalkSpeed = 500.f;
    GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
    GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

    //Mesh
    GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -100.0f), FRotator(0.0f, -90.0f, 0.0f));
    GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);
    GetMesh()->SetCollisionProfileName(TEXT("CharacterMesh"));

    static ConstructorHelpers::FObjectFinder<USkeletalMesh> CharaterMeshRef(TEXT("/Script/Engine.SkeletalMesh'/Game/InfinityBladeWarriors/Character/CompleteCharacters/SK_CharM_Cardboard.SK_CharM_Cardboard'"));
    if (CharaterMeshRef.Object)
    {
        GetMesh()->SetSkeletalMesh(CharaterMeshRef.Object); //분수대 만들었을 때처럼 오브젝트 지정
    }

    static ConstructorHelpers::FClassFinder<UAnimInstance> AnimInstanceRef(TEXT("/Game/ArenaBattle/Animation/ABP_ABCharacter.ABP_ABCharacter_C"));
    if (AnimInstanceRef.Class)
    {
        GetMesh()->SetAnimInstanceClass(AnimInstanceRef.Class); //클래스 정보 가지고 와서 지정
    }

    static ConstructorHelpers::FObjectFinder<UABCharacterControlData> ShoulderDataRef(TEXT("/Script/ArenaBattle.ABCharacterControlData'/Game/ArenaBattle/CharacterControl/ABC_Shoulder.ABC_Shoulder'"));
    if (ShoulderDataRef.Object)
    {
        CharacterControlManager.Add(ECharacterControlType::Shoulder, ShoulderDataRef.Object);
    }

    static ConstructorHelpers::FObjectFinder<UABCharacterControlData> QuaterDataRef(TEXT("/Script/ArenaBattle.ABCharacterControlData'/Game/ArenaBattle/CharacterControl/ABC_Quater.ABC_Quater'"));
    if (QuaterDataRef.Object)
    {
        CharacterControlManager.Add(ECharacterControlType::Quater, QuaterDataRef.Object);
    }
}

void AABCharacterBase::SetCharacterControlData(const UABCharacterControlData* CharacterControlData)
{
    // Pawn
    bUseControllerRotationYaw = CharacterControlData->bUseControllerRotationYaw;

    // CharacterMovement
    GetCharacterMovement()->bOrientRotationToMovement = CharacterControlData->bOrientRotationToMovement;
    GetCharacterMovement()->bUseControllerDesiredRotation = CharacterControlData->bUseControllerDesiredRotation;
    GetCharacterMovement()->RotationRate = CharacterControlData->RotationRate;
}

