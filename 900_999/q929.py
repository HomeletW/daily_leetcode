"""
929. Unique Email Addresses

Every valid email consists of a local name and a domain name,
separated by the '@' sign. Besides lowercase letters, the
email may contain one or more '.' or '+'.

For example, in "alice@leetcode.com", "alice" is the local name,
and "leetcode.com" is the domain name.

If you add periods '.' between some characters in the local name
part of an email address, mail sent there will be forwarded to
the same address without dots in the local name. Note that this
rule does not apply to domain names.
For example,
    "alice.z@leetcode.com" and "alicez@leetcode.com"
forward to the same email address.

If you add a plus '+' in the local name, everything after the
first plus sign will be ignored. This allows certain emails to
be filtered. Note that this rule does not apply to domain names.
For example,
    "m.y+name@email.com" will be forwarded to "my@email.com".
It is possible to use both of these rules at the same time.

Given an array of strings emails where we send one email to each
email[i], return the number of different addresses that actually
receive mails.

https://leetcode.com/problems/unique-email-addresses/
"""

from typing import List


class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        unique_emails = set()

        for email in emails:
            sep_index = email.find("@")
            local_name = email[:sep_index]
            domain = email[sep_index + 1:]
            local_name_split = local_name.split("+", maxsplit=1)
            local_name = local_name_split[0]
            local_name = local_name.replace(".", "")
            unique_emails.add(local_name + "@" + domain)

        return len(unique_emails)


print(Solution().numUniqueEmails(["a@leetcode.com", "b@leetcode.com", "c@leetcode.com"]))
