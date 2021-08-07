/* Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __mod_h2__h2_resp_head__
#define __mod_h2__h2_resp_head__

/* h2_resp_head is just the data belonging the the head of a HTTP response,
 * suitable prepared to be fed to nghttp2 for response submit. 
 */

struct h2_bucket;

typedef struct h2_resp_head {
    int stream_id;
    apr_status_t task_status;
    const char *http_status;
    struct h2_bucket *data;

    apr_size_t nvlen;
    const nghttp2_nv nv;

    long content_length;
    int chunked;
    
} h2_resp_head;

h2_resp_head *h2_resp_head_create(int stream_id,
                                  apr_status_t task_status,
                                  const char *http_status,
                                  apr_array_header_t *hlines,
                                  struct h2_bucket *data,
                                  apr_pool_t *pool);

void h2_resp_head_destroy(h2_resp_head *head);

long h2_resp_head_get_content_length(h2_resp_head *resp);

#endif /* defined(__mod_h2__h2_resp_head__) */
