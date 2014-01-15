//
//  GTRepository+RemoteOperations.h
//  ObjectiveGitFramework
//
//  Created by Etienne on 18/11/13.
//  Copyright (c) 2013 GitHub, Inc. All rights reserved.
//

#import <ObjectiveGit/ObjectiveGit.h>

@interface GTRepository (RemoteOperations)

// Fetch a remote.
//
// TODO: fetch refspec, progress ?
//
// remote  - The remote to fetch from.
// options - Options applied to the fetch operation.
//           Recognized options are :
//           `GTRemoteOptionsReferences`,
//           `GTRemoteOptionsCredentialProvider`,
//           `GTRemoteOptions`
// error   - The error if one occurred. Can be NULL.
//
// Returns YES if the fetch was successful, NO otherwise (and `error`, if provided,
// will point to an error describing what happened).
- (BOOL)fetchRemote:(GTRemote *)remote withOptions:(NSDictionary *)options error:(NSError **)error progress:(void (^)(const git_transfer_progress *stats, BOOL *stop))progressBlock;

// Push to a remote.
//
// TODO: progress ?
//
// remote  - The remote to fetch from.
// options - Options applied to the fetch operation.
//           Recognized options are :
//           `GTRemoteOptionsReferences`,
//           `GTRemoteOptionsCredentialProvider`,
// error   - The error if one occurred. Can be NULL.
//
// Returns YES if the fetch was successful, NO otherwise (and `error`, if provided,
// will point to an error describing what happened).
- (BOOL)pushRemote:(GTRemote *)remote withOptions:(NSDictionary *)options error:(NSError **)error progress:(void (^)(unsigned int current, unsigned int total, size_t bytes, BOOL *stop))progressBlock;

@end
