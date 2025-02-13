const originalArray = [
  {
    "MAGAMBO ISAAC": {
      initiatedPayments: [
        {
          amount: 20000.0,
          clientNames: "MAGAMBO ISAAC ",
          dated: "2024-04-01",
          mode: "manual",
          paymentId: "ZJdp1gZuc7Af",
          transactionId: "U6dUVGyYvY6z",
        },
        {
          amount: 100000000.0,
          clientNames: "EMMANUEL KUSIIMA ",
          dated: "2024-08-21",
          mode: "manual",
          paymentId: "JLjpksyEwzKF",
          transactionId: "V6FhOCpRh4lz",
        },
      ],
      totalPendingPaymentsAmount: 100020000.0,
    },
  },
  {
    "KIZZA HUSSEIN ": {
      initiatedPayments: [
        {
          amount: 10000.0,
          clientNames: "JOHN MUSISI ",
          dated: "2024-06-04",
          mode: "manual",
          paymentId: "LvQSaomSSxFx",
          transactionId: "IBZOCrul1CIn",
        },
        {
          amount: 10000.0,
          clientNames: "MUTABAZI ISAAC ",
          dated: "2024-06-08",
          mode: "manual",
          paymentId: "ym1AJzh7HdhT",
          transactionId: "ZfHb61ah4uNM",
        },
        {
          amount: 100000.0,
          clientNames: "SSENTEZA HAKIM ",
          dated: "2024-08-20",
          mode: "manual",
          paymentId: "wNdhRLwfCnVx",
          transactionId: "dYfpSvdIGGy4",
        },
      ],
      totalPendingPaymentsAmount: 120000.0,
    },
  },
  {
    "NDYABAHIKA DOUGLAS": {
      initiatedPayments: [
        {
          amount: 10000.0,
          clientNames: "AYEKUNDIRE ESTHER ",
          dated: "2024-06-14",
          mode: "manual",
          paymentId: "PzkHM0hWa21h",
          transactionId: "mG2zsB0DvL2x",
        },
        {
          amount: 1000.0,
          clientNames: "MAGOBA KINTU HO",
          dated: "2024-06-22",
          mode: "manual",
          paymentId: "nP0URUEl3pMP",
          transactionId: "cFYHOxq9ppeh",
        },
        {
          amount: 1000.0,
          clientNames: "MAGOBA KINTU HO",
          dated: "2024-06-22",
          mode: "manual",
          paymentId: "VUvbKRb7Nmxt",
          transactionId: "47lJdiLASByu",
        },
      ],
      totalPendingPaymentsAmount: 12000.0,
    },
  },
  {
    "TMACKNON UGANDA ": {
      initiatedPayments: [
        {
          amount: 20000.0,
          clientNames: "SONGA UMAR MOHAMMADSON",
          dated: "2024-09-02",
          mode: "manual",
          paymentId: "Z76EDfAHTTpI",
          transactionId: "fSsdEtmhGlVy",
        },
        {
          amount: 60000.0,
          clientNames: "SONGA UMAR MOHAMMADSON",
          dated: "2024-09-02",
          mode: "manual",
          paymentId: "8ufG8Ah3T4Tj",
          transactionId: "DTmHghKFVpAw",
        },
        {
          amount: 20000.0,
          clientNames: "SONGA UMAR MOHAMMADSON",
          dated: "2024-09-02",
          mode: "manual",
          paymentId: "PnkrTTq3QRUo",
          transactionId: "9PewEONClyIq",
        },
      ],
      totalPendingPaymentsAmount: 100000.0,
    },
  },
  {
    "SONGA ONE": {
      initiatedPayments: [
        {
          amount: 20000.0,
          clientNames: "SONGA UMAR MOHAMMADSON",
          dated: "2024-09-02",
          mode: "manual",
          paymentId: "OhvX4iq2BAyF",
          transactionId: "AymqUW7qoShE",
        },
        {
          amount: 60000.0,
          clientNames: "SONGA UMAR MOHAMMADSON",
          dated: "2024-09-02",
          mode: "manual",
          paymentId: "a76ThQzI67sY",
          transactionId: "Kc1YbFgT22b5",
        },
        {
          amount: 10000.0,
          clientNames: "SONGA UMAR MOHAMMADSON",
          dated: "2024-09-02",
          mode: "manual",
          paymentId: "nTfKORcHaplM",
          transactionId: "Oxs0Bhmqayw9",
        },
      ],
      totalPendingPaymentsAmount: 90000.0,
    },
  },
  {
    "ADRIKO TWO": {
      initiatedPayments: [
        {
          amount: 20000.0,
          clientNames: "SONGA UMAR MOHAMMADSON",
          dated: "2024-09-02",
          mode: "manual",
          paymentId: "Gp9S66tbbgtD",
          transactionId: "1letymx9CKJj",
        },
        {
          amount: 10000.0,
          clientNames: "SONGA UMAR MOHAMMADSON",
          dated: "2024-09-02",
          mode: "manual",
          paymentId: "UFn7OqV2qYrU",
          transactionId: "1IxP7dOcV7V7",
        },
      ],
      totalPendingPaymentsAmount: 30000.0,
    },
  },
  {
    "KABANDA HILLARY": {
      initiatedPayments: [
        {
          amount: 3000.0,
          clientNames: "NDUGA SAMUEL ",
          dated: "2024-09-09",
          mode: "manual",
          paymentId: "Q9xA4uu9f96G",
          transactionId: "ML4Sl4JVd1Ov",
        },
      ],
      totalPendingPaymentsAmount: 3000.0,
    },
  },
];

// Use Array.prototype.fill and Array.prototype.flat
const duplicatedArray = Array(20).fill(originalArray).flat();

console.log(duplicatedArray);
