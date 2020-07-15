//
//  CCTEtherLib.h
//  CCTEtherLib
//
//  Created by Helios on 2019/2/18.
//  Copyright © 2019 Helios. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 完整的 CCTEtherLib 代码，请加我的QQ：705356202
 **/

typedef NS_ENUM(NSInteger, CCTEtherError) {

    CCTEtherErrorMnemonicsLength = 0,       //0 助记词 长度不够
    CCTEtherErrorMnemonicsCount,            //1 助记词 个数不够
    CCTEtherErrorMnemonicsValidWord,        //2 某个 助记词有误（助记词有误)
    CCTEtherErrorMnemonicsValidPhrase,      //3 助记词 有误
    CCTEtherErrorPwdLength,                 //4 密码长度不够
    CCTEtherErrorKeyStoreLength,            //5 KeyStore长度不够
    CCTEtherErrorKeyStoreValid,             //6 KeyStore解密失败
    CCTEtherErrorPrivateKeyLength,          //7 私钥长度不够
    CCTEtherErrorAddressRepeat,             //8 钱包导入重复
    CCTWalletCreateSuc,                     //9 钱包创建成功
    CCTWalletImportMnemonicsSuc,            //10 助记词导入成功
    CCTWalletImportKeyStoreSuc,             //11 KeyStore导入成功
    CCTWalletImportPrivateKeySuc,           //12 私钥导入成功
    CCTEtherErrorNotGasPrice,               //13 获取GasPrice失败
    CCTEtherErrorNotNonce,                  //14 获取Nonce失败
    CCTEtherErrorMoneyMin,                  //15 转账金额太小 取消使用
    CCTEtherErrorNSOrderedDescending,       //16 余额不足 取消使用
    CCTEtherErrorPWD,                       //17 密码错误
    CCTEtherErrorSend,                      //18 转账失败
    CCTWalletSucSend,                       //19 转账成功
};

@interface CCTEtherLib : NSObject

/**
 创建钱包
 */
+(void)createWalletWithPwd:(NSString *)pwd
               resultBlock:(void(^)(NSString *addStr,NSString *keyStore,NSString *mnemonicPhrase,NSString *privateKey))block;

/**
 导入钱包：助记词
 */
+(void)importWalletWithMnemonic:(NSString *)mnemonic
                            pwd:(NSString *)pwd
                    resultBlock:(void(^)(NSString *address,NSString *keyStore,NSString *mnemonicPhrase,NSString *privateKey,BOOL suc,CCTEtherError error))block;

/**
 导入钱包：KeyStore
 @param keyStore keyStore文本，类似json
 */
+(void)importWalletWithKeyStore:(NSString *)keyStore
                            pwd:(NSString *)pwd
                    resultblock:(void(^)(NSString *address,NSString *keyStore,NSString *mnemonicPhrase,NSString *privateKey,BOOL suc,CCTEtherError error))block;

/**
 导入钱包： 私钥
 @param privateKey 私钥
 */
+(void)importWalletWithPrivateKey:(NSString *)privateKey
                              pwd:(NSString *)pwd
                      resultblock:(void(^)(NSString *address,NSString *keyStore,NSString *mnemonicPhrase,NSString *privateKey,BOOL suc,CCTEtherError error))block;

/**
 查询余额
 @param tokenArr 查询的代币的token
 @param address  eth地址
 */
+(void)getBalanceWithTokens:(NSArray<NSString *> *)tokenArr
                withAddress:(NSString *)address
                resultblock:(void(^)(NSArray *banlanceArr,BOOL suc))block;

/**
 转账
 
 @param toAddress 转入地址
 @param money 转入金额
 @param token 代币token 传nil为eth
 @param decimalCount  小数位数
 @param keyStore keyStore
 @param pwd 密码
 @param gasPrice gasPrice （建议10-20）建议传nil，默认位当前节点安全gasPrice
 @param gasLimit gasLimit 不传 默认eth 21000 token 60000
 @param block 回调
 */
+(void)transferToAssress:(NSString *)toAddress
                   Money:(NSString *)money
                   Token:(NSString *)token
            DecimalCount:(NSString *)decimalCount
         currentKeyStore:(NSString *)keyStore
                     pwd:(NSString *)pwd
                GasPrice:(NSString *)gasPrice
                GasLimit:(NSString *)gasLimit
             Resultblock:(void(^)(NSString *hashStr,BOOL suc,CCTEtherError error))block;

@end
